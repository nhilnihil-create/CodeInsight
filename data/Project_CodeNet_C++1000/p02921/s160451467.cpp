// Confessions of a Dangerous Mind

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 2e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 3e-16;

/*
	Keep moving forward. Take the Leap of Faith
*/

int main(){
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	string s, t; cin >> s >> t;
    
    long long cnt = 0, n = ll(s.size());

    for(long long i = 0; i < n; i++){
    	cnt += s[i] == t[i];
    }
    
    cout << cnt;
	return 0;
}