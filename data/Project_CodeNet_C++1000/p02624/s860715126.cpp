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
int main()
{
ll n;
cin>>n;
ll sum=0;
Rep(i,n+1){
    ll a=n/i;
    sum+=a*((a*i)+i)/2;
}
cout<<sum<<endl;
}

