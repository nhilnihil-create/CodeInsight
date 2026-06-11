#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int mod = 1000000007;

int main()
{
    IOS
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int H, W, K;
        cin >> H >> W >> K;
        vector<vector<char>> c(H, vector<char>(W));
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> c[i][j];
        int res = 0;
        for (int maskR = 0; maskR < (1 << H); maskR++)
        {
            for (int maskC = 0; maskC < (1 << W); maskC++)
            {
                int b = 0;
                for (int i = 0; i < H; i++)
                {
                    for (int j = 0; j < W; j++)
                    {
                        if (((maskR >> i)&1) == 0 && ((maskC >> j)&1) == 0)
                        {
                            if (c[i][j] == '#')
                                b++;
                        }
                    }
                }
                if (b == K)
                    res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}