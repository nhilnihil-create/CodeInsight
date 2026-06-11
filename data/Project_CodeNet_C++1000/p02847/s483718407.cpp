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

int sum(ll n) {
    int ans = 0;
    while(n) {
        ans +=  n%10;
        n /= 10;
    }
    return ans;
}

int main() {
	
    #ifndef ONLINE_JUDGE
        // read;
    #endif
    string s; cin >> s;
    vector<string> v = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int i = find(v.begin(), v.end(), s) - v.begin();
    cout << 7-i << nl;
	
	

	return 0;
}