#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    string s; cin>>s;
    ll ans=0;
    ll length=1;
    vector<int> v;
    if(s[0]=='>') v.push_back(0);
    rep(i,1,s.size()){
        if(s[i]==s[i-1]){
            length++;
        }else {
            v.push_back(length);
            length=1;
        }
    }
    v.push_back(length);
    if(s.back()=='<') v.push_back(0);
    // rep(i,0,v.size()) debug(v[i]);
    for(int i=0; i<v.size(); i+=2){
        ll large=max(v[i],v[i+1]);
        ll small=min(v[i],v[i+1]);
        // debug(large);
        // debug(small);
        ans+=large*(large+1)/2;
        ans+=small*(small-1)/2;
    }
    cout<<ans<<endl;
}