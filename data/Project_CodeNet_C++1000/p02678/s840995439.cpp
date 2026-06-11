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
int main(){
   ll  n,m;
   cin>>n>>m;
   rep(i,m){
       ll a,b;
       cin>>a>>b;
       a--;b--;
       to[a].push_back(b);
       to[b].push_back(a);
   }
   queue<int>q;
   vector<int> dist(n,inf);
   vector<int> pre(n,-1);
   dist[0]=0;
   q.push(0);
   while(!q.empty()){
       int v=q.front();
       q.pop();
       for(int u:to[v]){
           if(dist[u]!=inf)continue;
           dist[u]=dist[v]+1;
           pre[u]=v;
           q.push(u);
       }
   }
   cout<<"Yes"<<endl;
 
   Rep(i,n){
       cout<<pre[i]+1<<endl;
   }
}
