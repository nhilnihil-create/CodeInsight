#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s;
    cin >> s;
    string s2 = s + s;
    string tmp = s;
    ll k;cin >> k;
    ll cnt = 0;
    rep(i,s.size()-1) if(s[i]==s[i+1]){cnt++; s[i+1] = '#';}
    ll cnt2 = 0;
    rep(i,s2.size()-1) if(s2[i]==s2[i+1]){cnt2++;s2[i+1] = '#';}
    ll sa = cnt2 - 2*cnt;
    ll ans = cnt * k + sa * (k-1);
    string t = string(tmp.size(),tmp[0]);
    if(tmp == t){
        ans = s.size() * k /2;
    }
    if(s.size()==1){
        ans = k/2;
    }
    cout << ans << endl;
}