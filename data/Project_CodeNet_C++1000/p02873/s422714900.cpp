#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void rle(string s,vector<char> &cha,vector<ll> &num){
    ll a=0,cnt=0;
    string t;char x=s[0];
    while(a<s.size()){
        if(x==s[a])cnt++;
        else{
            cha.pb(x);num.pb(cnt);
            x=s[a];cnt=1;
        }
        a++;
    }
    cha.pb(x);num.pb(cnt);
}

int main(){
    string s;cin >> s;
    vector<char> cha;
    vector<ll> num;
    rle(s,cha,num);
    ll sum=0;
    ll t=cha.size();
    rep(i,t){
        if(i==0&&cha[0]=='>'){
            sum+=num[0]*(num[0]+1)/2;
            continue;
        }
        if(cha[i]=='>'){
            ll a=num[i-1],b=num[i];
            sum+=a*(a-1)/2;
            sum+=b*(b-1)/2;
            sum+=max(a,b);
        }
    }
    if(cha[t-1]=='<')sum+=num[t-1]*(num[t-1]+1)/2;
    cout << sum <<endl;
}