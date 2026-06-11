#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int a[N];
  map <int,long long> mp;
  for(int i=0;i<N;i++){
    cin>>a[i];
    mp[a[i]]++;
  }
  if((a[0]!=0)||(mp[0]!=1)){
    cout<<0<<endl;
    return 0;
  }
  int si=mp.size();
  long long ans=1;
  sort(a,a+N);
  int maxa=0;
  for(int i=0;i<N;i++){
    maxa=max(maxa,a[i]);
  }
  if(maxa!=si-1){
    cout<<0<<endl;
    return 0;
  }
  for(int i=2;i<si;i++){
    for(int j=0;j<mp[i];j++){
      ans=(ans*mp[i-1])%998244353;
    }
  }
  cout<<ans;
  return 0;
}
