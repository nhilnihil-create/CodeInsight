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

ll sum(ll l,ll r){
    return(l+r)*(r-l+1)/2;
}

int main(){
ll n;
cin>>n;
string s;
cin>>s;
vector<ll>v(n);
rep(i,n){
    if(s[i]=='R')v[i]=0;
    if(s[i]=='G')v[i]=1;
    if(s[i]=='B')v[i]=2;
    
}
vector<ll>cnt(3);
rep(i,n){
  cnt[v[i]]++;
}
ll ans=1;
rep(i,3){
    ans*=cnt[i];
}
rep(j,n)rep(i,j){
    ll k=j+j-i;
    if(k<n){
    if(v[k]==v[i])continue;
    if(v[i]==v[j])continue;
    if(v[k]==v[j])continue;
    ans--;
    }
}

cout<<ans<<endl;
return 0;
}

