// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include "bits/stdc++.h"

#define fastio      ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define TC          int t; cin >> t; for(int tc = 1; tc <= t; tc++)
#define read        freopen("input.txt", "r", stdin);
#define write       freopen("output.txt", "w", stdout);
#define nl          '\n'
#define pii		    pair<int, int>
#define ll 		    long long
#define pb		    push_back
#define eb		    emplace_back
#define all(v)	    v.begin(), v.end()
#define rall(v)	    v.rbegin(), v.rend()
#define d(x)	    cerr << #x << " = " << x << nl


using namespace std;

int main() {
	
    #ifndef ONLINE_JUDGE
        // read;
    #endif
    string s; int a; cin >> a >> s;
    for(int i = 0; i < (int) s.size(); i++) printf("%c", (s[i] + a > 90 ? s[i] + a - 26 : s[i] + a));
    cout << nl;
	

	return 0;
}