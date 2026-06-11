#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  sort(vec,vec+n);
  reverse(vec,vec+n);
  ll ans=0;
  ans+=vec[0];
  int x=2;
  for(int i=1;i<n-1;i++){
    if(x==n){
      break;
    }
    if(x>=n){
      ans-=vec[i-1];
      break;
    }
    ans+=vec[i]*2;
    x+=2;
  }
  cout<<ans<<endl;
}