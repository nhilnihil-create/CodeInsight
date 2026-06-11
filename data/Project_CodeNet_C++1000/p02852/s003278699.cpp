#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    reverse(all(s));
    ll cnt=0;
    bool f=1;
    rep(i,n){
        if(s[i]=='0')cnt=0;
        else cnt++;
        if(cnt==m)f=0;
    }
    if(!f){
        cout<<-1<<endl;
        return 0;
    }
    ll last=0;
    vector<ll>ans(0);
    ll k=0;
    cnt=0;
    rep(i,n+1){
        if(s[i]=='0'){
            k=i;
        }
        if(i-last==m||i==n){
            ans.pb(k-last);
            last=k;
        }
    }
    reverse(all(ans));
    rep(i,ans.size()){
        if(ans[i]==0)continue;
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}