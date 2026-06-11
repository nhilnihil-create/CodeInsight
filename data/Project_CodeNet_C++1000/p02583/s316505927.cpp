#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<iterator>
#include<vector>
using namespace std;
typedef vector<int> vii;
#define ll long long
#define tt ll t;cin>>t;while(t--)
#define nl endl
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define vec vector<ll>
#define cinv(v) for(auto it:v)cin >> it;
#define coutv(v) for(auto it:v)cout << it <<' ';cout<<endl;
#define so ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
        so;

        ll i,k,n,j,ctr=0,a[101],c;
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i];
          sort(a,a+n);
        for(i=0;i<n-2;i++){
          if(a[i]==a[i-1]);
          for(j=i+1;j<n-1;j++){
                   if(a[i]==a[j])continue;
                    for(k=j+1;k<n;k++){
                              if(a[j]==a[k])continue;
                              if((a[i]<(a[j]+a[k])&&a[j]<(a[i]+a[k])&&a[k]<(a[i]+a[j]))){
                                        ctr++;
                              }
                    }
          }

        }
        cout<<ctr;


        return 0;
}

