#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b){
    if(a%b==0)return b;
    else return gcd(b, a%b);
}

ll hlcm(ll a, ll b){
    if(a==0 || b==0) return 0;
    if(a<b)swap(a,b);
    if(a%b==0&&(a/b)%2==0) return 0;
    return a*b/gcd(b, a);
}

int main(){
    ll n, m;
    cin >> n>> m;
    vector<int> a(n), half(n);
    rep(i, n){
        cin>>a[i];
        half[i] = a[i]/2;
    }
    ll hlcm0 = half[0];
    rep(i, n-1){
        hlcm0 = hlcm(hlcm0, half[i+1]);
        if(hlcm0 > m||hlcm0==0){
            hlcm0=0;
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = (m/hlcm0 + 1) / 2;
    cout << ans << endl;
    return 0;
}