#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,K;
  cin>>N>>K;
  ll tmp=N%K;
  ll ans=min(tmp,abs(tmp-K));
  cout<<ans<<endl;

}