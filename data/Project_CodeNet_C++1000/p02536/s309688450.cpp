//2*10^9
//9*10^18
// __int128_t 
#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int

const ll M=1e9+7;

//to handle when remainder is -neg we add + M
//but when rem is +pos that time also we add so use %M
//so it will work for both
ll mod(ll n){
    return (n%M + M)%M; 
}
ll modAdd(ll a, ll b){
    return mod(mod(a)+mod(b));
}
ll modMul(ll a, ll b){
    return mod(mod(a)*mod(b));
}
ll modMinus(ll a, ll b){
    return mod(mod(a)-mod(b));
}
ll modpow(ll x, ll n) 
{ 
    if (n == 0) 
        return 1%M;
    if (n == 1)
        return x%M; 
    ll u = modpow(x,n/2); 
    u = modMul(u,u); 
    if (n%2) 
        u = modMul(u,x); 
    return u; 
}
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
bool isPrime(ll n){
    int end = sqrt(n);
    for(int i=2;i<=end;i++)
        if(n%i==0)
            return false;
    return true;
}

void travel(int start,vector<int> &visited,vector<vector<int>>&graph){
    visited[start]=1;
    for(int i=0;i<graph[start].size();i++){
        if(visited[graph[start][i]]==0)
            travel(graph[start][i],visited,graph);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
  
    
    int t=1;
    //cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> graph(n+1);
        vector<int> visited(n+1);
        int ans=0,s,d;

        for(int i=0;i<m;i++){
            cin>>s>>d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }

        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                ans+=1;
                travel(i,visited,graph);
            }
        }
        cout<<ans-1<<endl;
    }
    return 0;
}