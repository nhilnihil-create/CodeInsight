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
using P =pair<ll,ll>;

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

ll n;



    vector<pair<ll,ll>>p;
void fs(ll a){
    for(ll i=2;i*i<=n;i++){
        ll cnt=0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        p.emplace_back(i,cnt);
    }
    return;
}

const int m=2019;
ll di[]={1,0,-1,0};
ll dj[]={0,-1,0,1};
int main()
{
 ll n,k;
 cin>>n>>k;
 vector<ll>p(n);
 rep(i,n)cin>>p[i];
 vector<ll>c(n);
 rep(i,n)cin>>c[i];
 rep(i,n)p[i]--;    
 ll ans=-100000000000;
 rep(i,n){
     vector<ll>v;
     ll tot=0;
     ll now=i;
     ll tmp=k;
     while(0<tmp){
        now=p[now];
        tot+=c[now];
        v.push_back(c[now]);
        tmp--;
        if(now==i)break;
     }
     ll l=v.size();

     ll t;
     ll sum=0;
     rep(j,l+1){
      if(k<j+1)break;
      sum+=v[j];
      if(0<tot){
          ll e=(k-(j+1))/l;
          t=tot*e;
          ans=max(ans,sum+t);
      }
      ans=max(ans,sum);
     }
 }
 cout<<ans<<endl;
}
 


