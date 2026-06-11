#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,k,i,j,p;
  p=1000000007;
  cin >> n >> k;
  vector<int> a(n);
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  
  ll s=0,t=0;
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(a.at(i)>a.at(j)){
        s++;
      }
    }
  }
  
  s=(s*k)%p;
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(a.at(i)>a.at(j)){
        t++;
      }
    }
  }
  
  t=(t*(k*(k-1)/2%p))%p;
  
  cout << (s+t)%p << endl;
}