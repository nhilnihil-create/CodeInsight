#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
using Graph = vector<vector<int>>;
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int H, W, K, ans=0;
	cin >> H >> W >> K;
	vector<int> T(W), Y(H);
	vector<string> G(H);
	FOR(i, 0, H){
		cin >> G.at(i);
	}
	int a = 0;
	FOR(i, 0, H)
	{
		int c = 0;
		FOR(j, 0, W)
		{
			if(G.at(i).at(j)=='#'){
				c++;
				a++;
			}
		}
		Y.at(i) = c;
	}

	FOR(i,0,W){
		int c = 0;
		FOR(j, 0, H)
		{
			if(G.at(j).at(i)=='#')
				c++;
		}
		T.at(i) = c;
	}

	// {0, 1, ..., n-1} の部分集合の全探索
	for (int bit1 = 0; bit1 < (1 << H); ++bit1)
	{
		for (int bit2 = 0; bit2 < (1 << W); ++bit2)
		{
			int count = 0;
			vector<int> Ta, Yo;
			for (int i = 0; i < H; ++i)
			{
				if (bit1 & (1 << i))
				{ // i が bit1 に入るかどうか
					count += Y.at(i);
					Ta.push_back(i);
				}
			}
			for (int i = 0; i < W; ++i)
			{
				if (bit2 & (1 << i))
				{ // i が bit1 に入るかどうか
					count += T.at(i);
					Yo.push_back(i);
				}
			}
			FOR(i,0,Ta.size()){
				FOR(j,0,Yo.size()){
					if(G[Ta.at(i)][Yo.at(j)]=='#')
						count--;
				}
			}
			if(count==a-K){
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}



