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
 int n;
 cin>>n;
 vector<int> l(n);
 rep(i,n) cin>>l[i];
 sort(l.begin(),l.end());
 ll ans=0;
 rep(b,n)rep(a,b){
     int ab=l[a]+l[b];
     int r= lower_bound(l.begin(),l.end(),ab)-l.begin();
     int l=b+1;
     ans+=max(0,r-l);
 }
 cout<<ans<<endl;
}

