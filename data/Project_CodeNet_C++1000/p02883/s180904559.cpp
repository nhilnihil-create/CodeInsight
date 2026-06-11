#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  ll k;
  cin>>n>>k;
  ll sum=0;
  ll vec[n];
  ll vecb[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
    sum+=vec[i];
  }
  if(sum<=k){
    cout<<0<<endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    cin>>vecb[i];
  }
  sort(vec,vec+n);
  sort(vecb,vecb+n);
  reverse(vecb,vecb+n);
  ll ng=0,ok=1e12+1e5;
  ll check;
  ll zero=0;
  for(int t=0;t<40;t++){
    check=(ng+ok)/2;
    sum=0;
    for(int i=0;i<n;i++){
      sum+=max(zero,vec[i]-check/vecb[i]);
    }
    if(sum<=k){
      ok=check;
    }
    else{
      ng=check;
    }
  }
  cout<<ok<<endl;
}