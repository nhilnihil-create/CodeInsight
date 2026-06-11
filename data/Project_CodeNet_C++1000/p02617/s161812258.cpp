#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
 
int main(){
  int n;
  cin>>n;
  
  ll V=0, E=0;
  rep(i,n) V+=1ll*(i+1)*(n-(i+1)+1);
  
  
  rep(i,n-1){
    int u, v;
    cin>>u>>v;
    if(u>v) swap(u,v);
    E+=1ll*u*(n-v+1);
  }
  
  ll ans;
  ans=V-E;
  
  cout<<ans<<endl;
}