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


int main()
{
ll n,k;
cin>>n>>k;
ll cnt=0;
vector<ll>t(1000000);
vector<ll>town(n);
rep(i,n)cin>>town[i];
rep(i,n)town[i]--;
ll now=0;
while(0<k){  
    t[now]=cnt;
    now=town[now];
    k--;
    cnt++;
    if(t[now]!=0){
        ll a=cnt-t[now];
        k%=a;
        while(0<k){
            now=town[now];
            k--;
        }
    }
}
cout<<now+1<<endl;
}

