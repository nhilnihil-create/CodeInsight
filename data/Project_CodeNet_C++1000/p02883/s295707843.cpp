#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double Pi=acos(-1);
vector<ll> A;
vector<ll> F;
ll N,K,sumcost=0;
ll binary_search(ll key,ll maximum) {
  ll answer=maximum;
  ll left=1,right=maximum;
  while (right >= left) {
    ll count=0;
    ll mid=left+(right-left)/2;
    for(ll i=0;i<N;i++){count+=max((ll)0,A.at(i)-mid/F.at(N-1-i));}
    if (count > key){left=mid+1;}
    else if (count <= key){right=mid-1;answer=min(answer,mid);}
  }
  return answer;
}
int main() {
  cin>>N>>K;
  A.resize(N);
  F.resize(N);
  for(ll i=0;i<N;i++){
    cin>>A.at(i);
    sumcost+=A.at(i);
  }
  for(ll i=0;i<N;i++){cin>>F.at(i);}
  if(sumcost<=K){cout<<0<<endl;}//k回も修行する必要がない時
  else{
    sort(A.begin(),A.end());
    sort(F.begin(),F.end());
    ll maxtime=A.at((ll)A.size()-1)*F.at((ll)F.size()-1);
    cout<<binary_search(K,maxtime); 
  }
}