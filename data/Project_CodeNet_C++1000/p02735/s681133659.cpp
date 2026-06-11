#include <bits/stdc++.h>

using namespace std;    

const int maxn = 3e5 + 222;

int n, m;
char a[200][200];
int s[200][200];

int get(int xa, int ya, int xb, int yb) {
int sum = s[xb][yb];
sum -= s[xa - 1][yb];
sum -= s[xb][ya- 1];
sum += s[xa - 1][ya - 1];
return sum;
}
int dp[200][200];

int main () {                                          
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
	for(int i = 1; i <= n; i++){
	int cur = 0;
	for(int j = 1; j <= m; j++) {
		cin >> a[i][j], dp[i][j] = 1e8;
		cur += (a[i][j] == '#');

		s[i][j] = s[i - 1][j] + cur;
	}
	}


	dp[1][1] = (a[1][1] == '#');

	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i - 1; j++)
		if(get(j + 1, 1, i, 1) == (i - j))
		dp[i][1] = min(dp[i][1], dp[j][1] + 1);
		else {
			if(a[i][1] == '.')
				dp[i][1] = min(dp[i][1], dp[i - 1][1]);
		}
	for(int j = 1; j <= m; j++)
		for(int i = 0; i <= j - 1; i++)
		if(get(1, i + 1, 1, j) == j - i)
			dp[1][j] = min(dp[1][j],dp[1][i] + 1);
		else if(a[1][j]=='.')
			dp[1][j] =min(dp[1][j],dp[1][j-1]);
	for(int i = 0; i <= max(n, m); i++)
		dp[0][i]=dp[i][0]=1e6;
	for(int i = 2; i <= n; i++)
	for(int j = 2; j <= m; j++) {
		for(int k = 1; k <= i; k++)
		for(int l = 1; l <= j; l++) {
		int mn = min(dp[k - 1][l], dp[k][l - 1]);
		if(mn > 1e6) continue;
		if(get(k , l , i, j) != (i - k + 1) * (j - l + 1) && a[i][j] == '#') continue;
		if(a[i][j] =='#'){

			int val = 0;
			if(a[k - 1][l]!='#') val = 1;dp[i][j]=min(dp[i][j], dp[k - 1][l] + val);
			val = 0;
			if(a[k][l - 1]!='#') val = 1;dp[i][j]=min(dp[i][j], dp[k][l-1] + val);
		}
		else if(a[i][j]=='.'){
			if(abs(i - k) + abs(j - l) == 1) 
				dp[i][j] = min(dp[i][j], dp[k][l]);
		}
		}
	}
	for(int i = n; i <= n; i++, cout << endl)
	for(int j = m; j <= m; j++)
	cout<<dp[i][j];
	return 0;
}
                                               