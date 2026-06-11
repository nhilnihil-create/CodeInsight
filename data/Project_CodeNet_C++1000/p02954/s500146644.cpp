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
 vector<ll>cnt(s.size());
 ll x;
 
 rep(i,s.size()){
    ll k=0;
    ll j=i;
    if(s[i]=='L'){
        while(s[j]=='L'){
            j++;
            k++;
        }
       cnt[i]+=(k/2+k%2);
       cnt[i-1]+=(k/2);
       i+=k-1;
       continue;
    }
    if(s[i]=='R'){
        while(s[j]=='R'){
            j++;
            k++;
        }
        ll left=100000-k;
        if(left%2==0){
          cnt[j]+=(k/2+k%2);
          cnt[j-1]+=(k/2);
        }else{
          cnt[j-1]+=(k/2+k%2);
          cnt[j]+=(k/2);
        }
        i+=k-1;
        continue;
    }
 }
 rep(i,s.size())cout<<cnt[i]<<" ";
}

