#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<ll>d(N);
  for(ll i=0;i<N;i++)cin>>d[i];
  sort(d.begin(),d.end());
  cout<<d[N/2]-d[N/2-1]<<endl;
}