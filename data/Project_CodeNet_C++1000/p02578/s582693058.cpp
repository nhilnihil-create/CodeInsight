#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int N = 2e5+5;


vector<ll>ans,veca,vecb;
vector<int>adj[N];
vector<double>aka;
vector<pair<int,double>>dp[N];
vector<bool>vis;


void init(int n){
    ans.clear();veca.clear();aka.clear();vis.clear();ans.resize(n);
    vecb.clear(),vecb.resize(n);veca.resize(n);vis.resize(n);
    for (int i = 0; i <n; i++) {
        vis[i]=0;
    }
    for (int i = 0; i<=n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i <=n; i++) {
        dp[i].clear();
    }
    for (int i = 0; i < n; i++) {
        ans[i]=0;
    }
}
int power(int a,int n){
    int res=1;
    for (int i = 0; i < n; i++) {
        res=(1LL*res*a)%mod;
    }
    return res%mod;
}
int add(int a){
    if(a<0) a+=mod;
    return a;
}
void solve(){
    int n;
    cin>>n;
    init(n);
    for (int i = 0; i <n; i++) {
        cin>>veca[i];
    }
    int flag=veca[0];
    for (int i = 1; i < n; i++) {
        if(veca[i]<flag){
            ans[i]=(flag-veca[i]);
            continue;
        }
        flag=veca[i];
    }
    ll cnt=0;
    for (int i = 0; i < n; i++) {
        cnt+=ans[i];
    }
    cout<<cnt<<"\n";
}

int main(){
   
   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
        
        
    return 0;
}