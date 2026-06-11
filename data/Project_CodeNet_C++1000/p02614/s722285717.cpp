#include <bits/stdc++.h>
using namespace std;

int H, W, K;
vector<vector<char>> masu;

void input()
{
	cin >> H >> W >> K;
    masu = vector<vector<char>> (H, vector<char>(W));
	for (int i=0; i<H; i++)
	{
		string str;
		cin >> str;
		for (int j=0; j<W; j++) 
        {
            masu[i][j] = str[j];
        }
	}
}


void solve()
{
	int row_bits = pow(2, H);
	int col_bits = pow(2, W);
	// 行と列の選び方 <= 2^12
	// それぞれに対して黒マスの数え上げが36マス
	// O(2^12 * 36) 4048*36
	// ビットが立ってなければ赤に塗り潰し
	int ans = 0;
	for (int i=0; i<=row_bits; i++)
	{
		for (int j=0; j<=col_bits; j++)
		{
            // 塗り潰しのパターンに対して黒マスの数え上げ
			int kuro=0;
			for (int k=0; k<H; k++)
			{
				if (i & (1<<k))
					for (int l=0; l<W; l++)
					{
						if ((j & (1<<l)) && masu[k][l]=='#') kuro++; 
					}
			}
            if (kuro==K) ans++;
            //if (kuro==K) cout << i << " " << j << endl;
		}
	}
	cout << ans << endl;
}

int main()
{
	input();
	solve();
}
