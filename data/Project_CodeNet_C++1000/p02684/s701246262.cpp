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



int main()
{
ll n,k;
cin>>n>>k;
vector<ll>v(n);
rep(i,n){
    ll a;
    cin>>a;
    v[i]=a-1;
}
ll now=0;

vector<ll>c(n,-1);


for(ll l=0;l<k;l++){
    if(c[now]==-1){
        c[now]=l;
    }else{
            ll m=l-c[now];
            ll b=k-l;
            ll d=b%m;
            for(ll j=0;j<d;j++){
                now=v[now];
                if(j==d-1){
                    cout<<now+1<<endl;
                    return 0;
                }
            }
        }
    
    now=v[now];
}
cout<<now+1<<endl;

}

