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
 string s;
 cin>>s;
 ll n;
 cin>>n;
 ll cnt=0;
 rep(i,n){
  ll a;
  cin>>a;
  if(a==1)cnt++;
  if(a==2){
      ll b;
      string c;
      cin>>b>>c;
      if(cnt%2==1){
          if(b==1)b=2;
          else b=1;
      }
      if(b==1)s.insert(0,c);
      if(b==2)s+=c;
  }
 }
 if(cnt%2==1)reverse(s.begin(),s.end());
cout<<s<<endl;
}

