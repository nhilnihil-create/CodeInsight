#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
const int mod=1e9+7;
const ll N = 4e5+5;


vector<ll>ans,veca,vecb;
vector<int>adj[N];
vector<double>aka;
vector<pair<int,double>>dp[N];
vector<bool>vis;


void init(int n){
    ans.clear();veca.clear();aka.clear();vis.clear();
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
    int akash=(power(10,n)%mod)-((2LL*(power(9,n)))%mod)+(power(8,n)%mod);
    akash=add(akash);
    cout<<akash<<"\n";
    
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