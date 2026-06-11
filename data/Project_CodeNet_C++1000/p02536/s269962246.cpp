#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#define mod 1000000007
#define ll long long int
#define int int64_t
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SORT(x) sort(all(x));
#define DSORT(x) sort(all(x), greater<>());
#define PI 3.14159265358979323846264338327950288
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
bool prime(int n){for(int i=2;i<=sqrt(n);i++){if(n%i==0){return 0;}}return 1;}
void normal(int &a) {a=a%mod;(a<0)&&(a=a+mod);}
int Add(int a,int b) {a=a%mod,b=b%mod; normal(a),normal(b); return (a+b)%mod; }
int Sub(int a,int b) {a=a%mod,b=b%mod; normal(a),normal(b); a=a-b; normal(a); return a; }
int Mul(int a,int b) {a=a%mod,b=b%mod; normal(a),normal(b); return (a*b)%mod;}
int Pow(int n,int x){int res=1; while(x){ if(x&1) res=Mul(res,n); n=Mul(n,n); x=x>>1;} return res;} 
int modInverse(int n){return Pow(n,mod-2);}
int Div(int a,int b) { return Mul(a, modInverse(b));}
const int E3 = 1e3 + 7;
const int E4 = 1e4 + 7;
const int E5 = 1e5 + 7;
const int E6 = 1e6 + 7;
const int E9 = 1e9 + 7;
vector<int> adj[E5];
bool vis[E5];
void dfs(int node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
signed main(){
    fio;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int cnt=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

