#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long
int main() {
   ll n;
   cin>>n;
    ll a[n];
    ll i,j,k,p;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll cnt=0,l=0,h=0;
    for(i=0;i<n;i++)
        for(j=0;j<i;j++)
            for(k=0;k<j;k++)
                if(a[i]!=a[j] && a[j]!=a[k] && a[i] < a[j] + a[k]) cnt++;
    cout<<cnt<<endl;
    
}
