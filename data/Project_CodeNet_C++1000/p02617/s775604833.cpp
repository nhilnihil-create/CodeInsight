#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
typedef long long ll;
using namespace std;

int main(){
    IOS

    int n;
    cin >> n;
    ll V = 0, E = 0;
    FOR(i,1,n){
        V += i * (n - i + 1);
    }
    FOR(i,1,n-1){
        ll u, v;
        cin >> u >> v;
        if(u > v)
            swap(u, v);
        E += u * (n - v + 1);
    }
    cout << V - E;

    return 0;
}