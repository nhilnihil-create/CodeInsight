#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
ll N;
int main(){
  cin>>N;
  vector<P>A(N);
  for(int i=0;i<N;i++){
  ll x,l;cin>>x>>l;
    P p(x+l,x-l);
    A[i]=p;
  }sort(A.begin(),A.end());
  ll ans=0;ll r=-1000000000000;
  for(int i=0;i<N;i++)
  if(r<=A[i].second){ans++;
    r=A[i].first;
                    }
  cout<<ans<<endl;
  return 0;
}