#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n; cin>> n;
    vector<ll> a(n+1), b(n);
    forin(a);
    forin(b);

    ll rem;
    ll ans=0;
    ll zero=0;
    rep(i, n){
        rem=max(zero, b[i] - a[i]);
        ans += min(rem, a[i+1]);
        a[i+1] -= min(rem, a[i+1]);
        ans += min(a[i], b[i]);
    }
    cout<< ans << endl;
}