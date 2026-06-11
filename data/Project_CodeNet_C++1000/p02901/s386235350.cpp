#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=998244353;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e9;
const long double PI=acos(-1);

int n,m;
int a[1003],b[1003];
int msk[6000];

int memo[1003][5000];
int mx;

int dp(int idx,int msk1){
    if(idx==m){
        if(msk1==mx){
            return 0;
        }
        return 1e9;
    }
    if(memo[idx][msk1]!=-1)return memo[idx][msk1];
    int tmp=msk1 | msk[idx];
    int ch1=dp(idx+1,tmp)+a[idx];
    int ch2=dp(idx+1,msk1);
    return memo[idx][msk1]=min(ch1,ch2);
}

void solve(int T){
    memset(memo,-1,sizeof(memo));
    //cout<<memo[10][10]<<"\n";
    cin>>n>>m;
    mx=((1<<n)-1);
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<b[i];j++){
            int x;
            cin>>x;
            msk[i]|=(1<<(x-1));
        }
    }
    int ans=dp(0,0);
    cout<<((ans!=1e9)?ans:-1)<<"\n";
}

int main() {
    //fastio

    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}
