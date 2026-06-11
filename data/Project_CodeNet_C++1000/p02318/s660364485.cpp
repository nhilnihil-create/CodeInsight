#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll LevenshteinDistance(const string& s1, const string& s2){

    const ll N1 = s1.size();
    const ll N2 = s2.size();

    ll dp[N1+1][N2+1] = {};

    for(int i=0; i<=N1; i++) {
	dp[i][0] = i;
    }
    for(int j=0; j<=N2; j++) {
	dp[0][j] = j;
    }

    for(int i=0; i<N1; i++) {
	for(int j=0; j<N2; j++) {
	    ll a = (s1[i] == s2[j] ? 0 : 1);
	    dp[i+1][j+1] = min( dp[i][j] + a, dp[i][j+1]+1);
	    dp[i+1][j+1] = min( dp[i+1][j+1], dp[i+1][j]+1);
	}
    }
    return dp[N1][N2];
    
}

int main () {

    string s1,s2;
    cin >> s1 >> s2;
    cout << LevenshteinDistance(s1,s2) << endl;

    return 0;
}