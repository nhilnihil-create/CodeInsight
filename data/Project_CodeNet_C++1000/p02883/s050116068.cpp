#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
using Graph=vector<vector<int>>;

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N),F(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>F.at(i);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  sort(F.begin(),F.end());

  ll left=0;
  ll right=1000000000000;
  ll x;
  while(left+1<right){
    x=(left+right)/2;
    ll count=0;
    for(int i=0;i<N;i++){
      count+=max<ll>(A.at(i)-x/F.at(i),0);
    }
    if(count<=K){
      right=x;
    }else{
      left=x;
    }
  }

  x=(left+right)/2;
  ll count=0;
  for(int i=0;i<N;i++){
    count+=max<ll>(A.at(i)-x/F.at(i),0);
  }
  if(count<=K){
    right=x;
  }else{
    left=x;
  }

  cout<<right<<endl;
}
