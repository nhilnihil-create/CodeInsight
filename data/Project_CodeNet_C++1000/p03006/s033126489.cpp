#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,count=0; cin>>N;
  vector<pair<ll,ll>>A;
  map<pair<ll,ll>,ll>M;
  for(int i=0; i<N; i++){
    ll x,y; cin>>x>>y;
    A.push_back(make_pair(x,y));
  }
  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      ll a,b;
      a=(A[i].first-A[j].first);
      b=(A[i].second-A[j].second);
      if(a<0) a*=-1, b*=-1;
      if(a==0 && b<0) b*=-1;
      ll value=M[make_pair(a,b)];
      value++;
//      cout<<"value:"<<value<<" a:"<<a<<" b:"<<b<<endl;
      count=max(count,value);
      M[make_pair(a,b)]=value;
    }
  }
  cout<<N-count<<endl;
}