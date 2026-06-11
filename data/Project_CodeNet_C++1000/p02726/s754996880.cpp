 #include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<int,int>;

ll f(ll x,ll c,ll d){
    ll res =x;
    res -=x/c;
    res -=x/d;
    res+= x/lcm(c,d);
    return res;
}

vector<int> to[100005];
const ll inf =100000000;

vector<ll>a,b,c,d;
ll n,m,q;
ll ans=0;
void bfs(vector<ll> v){
   if(v.size()==n+1) {
       ll sum=0;
       rep(i,q){
           if(v[b[i]]-v[a[i]]==c[i])sum+=d[i];
       }
       ans=max(ans,sum);
       return;
   }
   v.push_back(v.back());
   bfs(v);
   while(v.back()<m){
       v.back()++;
       bfs(v);
   }
}

int main(){
 int n,x,y;
 cin>>n>>x>>y;
 x--;y--;
 vector<int>ans(n);
 rep(sv,n){
     vector<int> dist(n,inf);
     queue<int>q;
     auto push =[&](int v,int d){
         if(dist[v]!=inf)return;
         dist[v]=d;
         q.push(v);
     };
  push(sv,0);
  while(!q.empty()){
    int v=q.front();q.pop();
    int d=dist[v];
    if(v-1>=0)push(v-1,d+1);
    if(v+1<n)push(v+1,d+1);
    if(v==x)push(y,d+1);
    if(v==y)push(x,d+1);
  }
  rep(i,n) ans[dist[i]]++;
 }
 rep(i,n)ans[i]/=2;
 for(int i=1;i<=n-1;i++){
     cout<<ans[i]<<endl;
 }
 return 0;
}
