#include <bits/stdc++.h>
#define ll long long int
#define ld long double
const ll MOD = 998244353;
const ll INF = 1e18;
using namespace std;


main(){    
    #ifdef XOX
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\Input.txt", "r", stdin);
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\OPT.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    ll d = 0, s = 0;
    ll u, v;
    for(int i = 0; i < n; i++){
        cin >> u >> v;  
        d += v, s += u*v;
    }

    cout << d - 1ll + ((s - 1) / 9ll);
}