#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll =unsigned long long;
using dl = long double;
const ll m=1000000007;

ll fac[1000001];

void pre(){
    fac[0]=fac[1]=1;
    for(int i=2;i<=1000001;i++)
{

    fac[i]=(fac[i-1]*1LL*i)%m;
}
}

ll power(ll a,ll n){
    ll res=1;
    while(n){

    if(n%2)
        res = (res*1LL*a)%m;

        n/=2;
        a=(a*1LL*a)%m;

    }
    return res;

}

ll nCr(ll n,ll r){


ll res= fac[n];
res = (res*1LL*power(fac[r],m-2))%m;
res= (res*1LL*power(fac[n-r],m-2))%m;
return res;

}



int main()
{
    pre();
    ll x,y;
    cin>>x>>y;
    int z=max(x,y);
   int necr=x;
   int necc=y;
   ll ans=0;
   ll one = (2*y-x)/3;

   ll two = (2*x-y)/3;
   if(one<0||two<0||(2*y-x)%3!=0)cout<<0<<endl;
   else if(one+two==0||one+two<0||(2*x-y)%3!=0)cout<<0<<endl;
   else{
    ll a= one;
    ll b= two;
   // cout<<one<<" "<<two<<endl;
    //cout<<a<<b;
    ll f=1;ll nos = a+b;

    cout<<nCr(nos,a);

   }


    return 0;
}
