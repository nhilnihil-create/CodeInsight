// Sky's the limit :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

int fun(int&x, int y) {

}
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //int t = 1; cin >> t; while(t--)
    {
    	int h, w;
    	cin >> h >> w;
    	string s[h];
    	for(int i = 0; i < h; i++)
    		cin >> s[i];

    	int dp[h][w];
    	for(int i = 0; i < h; i++) {
    		for(int j = 0; j < w; j++)
    			dp[i][j] = LLONG_MAX;
    	}

    	dp[0][0] = (s[0][0] == '#');
    	for(int i = 0; i < h; i++) {
    		for(int j = 0; j < w; j++) {
    			if(!i && !j)
    				continue;
    			if(i)
    				dp[i][j] = min(dp[i][j], dp[i - 1][j] + (s[i][j] == '#' && s[i - 1][j] == '.'));
    			if(j)
    				dp[i][j] = min(dp[i][j], dp[i][j - 1] + (s[i][j] == '#' && s[i][j - 1] == '.'));
    		}
    	}

    	cout << dp[h - 1][w - 1] << '\n';
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}

