#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
string s;
ll N;
vector<vector<ll> > memo(100006,vector<ll>(2,-INF));
//check:L以下が確定した
ll rec(ll now,ll check){
    if(memo[now][check]!=-INF) return memo[now][check];
    
    if(now==0){
        if(check==1){
            return memo[now][check]=(s[now]=='1'?1:0);
        }
        else{
            return memo[now][check]=(s[now]=='1'?2:1);
        }
    }
    
    if(check==1){
        return memo[now][check]=((rec(now-1,1)*3)%MOD + (rec(now-1,0)*(s[now]=='1'?1:0))%MOD)%MOD;
    }
    else{
        return memo[now][check]=(rec(now-1,0)*(s[now]=='1'?2:1))%MOD;
    }
}
int main(){
    cin>>s;
    N=sz(s);
    cout<<(rec(N-1,1)+rec(N-1,0))%MOD<<endl;
}


