#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    ll a, b; cin >> a >> b;
    ll gc = __gcd(a,b);
    set<ll> s;
    for(ll i = 2; i * i <= gc; ++i){
        while(gc % i == 0){
            s.insert(i);
            gc /= i;
        }
    }
    if(gc > 1) s.insert(gc);
    cout << s.size() + 1 << '\n';
    return  0;
}