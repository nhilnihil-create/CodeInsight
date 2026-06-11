#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin >>n;
  vector<long long>a(n+1);
  for(long long i=0;i<=n;i++)cin>>a[i];
  if(n==0){
    if(a[0]==1){
      cout<<1<<endl;
      return 0;
    }else{
      cout<<-1<<endl;
      return 0;
    }
  }
  if(a[0]==1){
    cout<<-1<<endl;
    return 0;
  }
  vector<long long>wa(n+1,0);
  wa[n]=a[n];
  for(long long i=n-1;i>=0;--i){
    wa[i]+=a[i]+wa[i+1];
  }
  long long kotae=1;
  long long chouten=1;
  for(long long i=1;i<n+1;i++){
    if(chouten>=LLONG_MAX/2){
      chouten==LLONG_MAX;
    }else{
      chouten*=2;
    }
    kotae+=min(chouten,wa[i]);
    //cout<<i<<" "<<chouten<<" "<<wa[i]<<" "<<kotae<<endl;
    if(a[i]!=0){
      chouten-=a[i];
      if(chouten<0){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  cout<<kotae<<endl;
  return 0;
}