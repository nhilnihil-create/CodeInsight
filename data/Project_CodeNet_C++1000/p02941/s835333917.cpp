#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll ans=0;
  ll vec[n],vecb[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  for(int i=0;i<n;i++){
    cin>>vecb[i];
    if(vecb[i]<vec[i]){
      cout<<-1<<endl;
      return 0;
    }
  }
  for(int q=0;q<60;q++){
  for(int i=0;i<n;i++){
    if(vecb[i]>vecb[(i+1)%n]&&vecb[i]>vecb[(i+n-1)%n]&&vecb[i]!=vec[i]){
      if(vecb[i]<vec[i]+vecb[(i+1)%n]+vecb[(i+n-1)%n]){
        cout<<-1<<endl;
        return 0;
      }
      ll x=(vecb[i]-max(vecb[(i+1)%n],vecb[(i+n-1)%n])+vecb[(i+1)%n]+vecb[(i+n-1)%n]-1)/(vecb[(i+1)%n]+vecb[(i+n-1)%n]);
      x=min(x,(vecb[i]-vec[i]+vecb[(i+1)%n]+vecb[(i+n-1)%n]-1)/(vecb[(i+1)%n]+vecb[(i+n-1)%n]));
      vecb[i]-=(vecb[(i+1)%n]+vecb[(i+n-1)%n])*x;
      ans+=x;
    }
  }
  }
  
  for(int i=0;i<n;i++){
    if(vecb[i]!=vec[i]){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<ans<<endl;
}