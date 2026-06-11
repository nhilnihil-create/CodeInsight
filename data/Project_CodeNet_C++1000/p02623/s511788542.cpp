#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

typedef long long ll;
using namespace std;



bool isPrime(int n){
    if(n < 2){
        return 0;
    }
    if(n%2 == 0){
        return n==2;
    }
    for(int i=3;i*i<=n;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}


int main() {

    ll n,m,k;
   cin>>n>>m>>k;
   vector<ll> a(n);
   vector<ll> b(m);
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<m;i++)cin>>b[i];
   ll t = 0;
   ll no1 = 0;
   ll no2 = 0;
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    for(int i=1;i<m;i++)b[i]+=b[i-1];
    for(int i=0;i<n;i++){
        ll curr = a[i];
      //  cout<<curr<<endl;
        if(curr> k) break;
        auto it = lower_bound(b.begin(),b.end(),k-curr+1);
        int indx = it-b.begin();
       // cout<<"indx "<<indx<<" val "<<*it<<endl;
        if(indx <= 0 ) indx=0;
        no1 = max((ll)(i+1+indx),no1);
    }
    for(int i=0;i<m;i++){
        ll curr = b[i];
        if(curr> k) break;
        auto it = lower_bound(a.begin(),a.end(),k-curr+1);
        int indx = it-a.begin();
        if(indx <= 0 ) indx=0;
        no2 = max((ll)(i+1+indx),no2);
    }

    cout<<max(no1,no2)<<endl;

   
    return 0;
}
