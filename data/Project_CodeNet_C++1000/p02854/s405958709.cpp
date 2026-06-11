#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  ll N,sum=0,sum11=0,sum12,sum21=0,sum22;
  cin>>N;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
    sum+=vec.at(i);
  }
  for(ll i=0;i<N;i++){
    sum11+=vec.at(i);
    if(2*sum11==sum){cout<<0<<endl;return 0;}
    if(2*sum11>sum){sum12=sum-sum11;break;}
  }
  for(ll i=0;i<N;i++){
    sum21+=vec.at(N-1-i);
    if(2*sum21>sum){sum22=sum-sum21;break;}
  }
  //cout<<sum11<<" "<<sum12<<" "<<sum21<<" "<<sum22<<endl;
  if(sum12<sum22){sum11=sum21;sum12=sum22;}
  cout<<sum11-sum12<<endl;
} 