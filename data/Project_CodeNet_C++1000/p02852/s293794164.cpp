#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

//Sugoroku
//入力
ll n,m;
string s;

int main(){
    cin >> n >> m;
    cin >> s;
    vector<ll>ans;
    ll l = s.size();
    int i=l-1;
    while(i>0){
        for(int j=m;j>=0;j--){
            if(j==0){
                cout << -1 << endl;
                return 0;
            }
            ll now = i-j;
            if(now<0)continue;
            if(s[now]=='1')continue;
            ans.push_back(j);
            i=now;
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}
