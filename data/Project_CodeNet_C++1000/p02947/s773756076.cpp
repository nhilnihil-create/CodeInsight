#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    ll n; cin>> n;
    map<string, ll> m;
    vector<string> s(n);
    ll ans=0;
    rep(i, n){
        cin>> s[i];
        sort(s[i].begin(), s[i].end());
        m[s[i]]++;
        if(m[s[i]] != 1) ans += m[s[i]] -1;
    }

    cout<< ans << endl;
}