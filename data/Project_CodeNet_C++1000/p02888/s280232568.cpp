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
ll ans=-1000000000;



int main()
{
 ll n;
 cin>>n;
 vector<ll>v(n);
 rep(i,n)cin>>v[i];
 sort(v.rbegin(),v.rend());
 ll ans=0;
 rep(i,n){
     ll a=v[i];
     for(ll k=i+1;k<n;k++){
         ll b=v[k];
         for(ll l=k+1;l<n;l++){
             ll c=v[l];
             if(a>=c+b)break;
             ans++;
         }
     }
 }
 cout<<ans<<endl;

}

