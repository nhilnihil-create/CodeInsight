#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;


ll gcd(ll x,ll y){return y ? gcd(y,x % y) : x;}

int main(){
    ll a,b;
    cin >> a >> b;
    ll g = gcd(a,b);
    set<ll> s;
    s.insert(1);
    for(ll i = 2;i * i <= g;i++){
        if(g == 1) break;
        while(g % i == 0){
            g /= i;
            s.insert(i);
        }
    }
    if(g!=1)s.insert(g);
    cout << s.size() << endl;
    
}