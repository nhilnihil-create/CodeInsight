#include <bits/stdc++.h>
using namespace std;


int LCS(const string& a, const string& b) {
    int ans = 0;
    const int len_a = a.length(), len_b = b.length();

    int dp[len_a + 1][len_b + 1] = {};
    for(int i=1; i<=len_a; i++) {
	for(int j=1; j<=len_b; j++) {
	    dp[i][j] = max(dp[i][j], dp[i-1][j] );
	    dp[i][j] = max(dp[i][j], dp[i][j-1] );
	    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (a[i-1] == b[j-1] ? 1 : 0) );
	}
    }
    ans = dp[len_a][len_b];
    return ans;
}

int main() {

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
	string a,b;
	cin >> a >> b;
	cout << LCS(a,b) << endl;
    }
    return 0;
}