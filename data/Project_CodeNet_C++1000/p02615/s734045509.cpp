#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define lli long long int
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define vii vector<lli>

#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<lli,lli>>
#include <map>           
lli mod=1000000007;      

int main(){
  lli n;
  cin>>n;
  vii v(n);
  
  foo(i,n) cin>>v[i];
  sort(v.begin(),v.end(),greater<lli>());
  
  lli s=v[0];
  lli t=n-2;
  int i=1;
  int c=0;
  while(t--){
    s+=v[i];
    c++;
    if(c==2){
      i++;
      c=0;
    }
  }
  cout<<s;
}