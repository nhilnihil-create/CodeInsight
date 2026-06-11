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

ll ketasu(ll a){
   ll num=1;
   while(a/10){
       num++;
       a/=10;
   }
   return num;
}

ll gcd(ll a,ll b){return b ? gcd(b,a%b) :a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

ll kosuu(ll a){
    ll sum=0;
    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            if(a!=1&&i*i!=a){
            sum+=2;
            }else{
             sum++;   
            }
        }
    }
    return sum;
}




    vector<pair<ll,ll>>p;

ll n,m,q;
vector<ll>a,b,c,d;
ll ans=0;
void dfs(vector<ll> v){
    if(v.size()==n){
      ll sum=0;
      rep(i,q)if(v[b[i]]-v[a[i]]==c[i])sum+=d[i];
      ans=max(ans,sum);
      return;
    }
    if(v.size()==0)v.push_back(1);
    v.push_back(v.back());
    dfs(v);
    while(v.back()<m){
        v.back()++;
        dfs(v);
    }
    return;
}


int main()
{
 cin>>n>>m>>q;
 a=b=c=d=vector<ll>(q);
 rep(i,q){
     cin>>a[i]>>b[i]>>c[i]>>d[i];
     a[i]--;b[i]--;
 }
 dfs(vector<ll>());
 cout<<ans<<endl;
}

