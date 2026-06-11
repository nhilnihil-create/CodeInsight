#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
  ll N; cin>>N;
  vector<ll> a(N);
  for(ll i=0; i<N; i++){
    cin>>a[i];
  }
  sort(begin(a),end(a),greater<ll>());
  using tup = tuple<ll,ll,ll>;
  queue<tup> q;
  ll sum = a.front();
  tup t=make_tuple(0,1,a[1]);
  q.push(t);
  t=make_tuple(0,1,a[1]);
  q.push(t);

  for(ll i=2; i<N; i++){
    tup tt = q.front();
    q.pop();
    sum += get<2>(tt);
    tup t0=make_tuple(get<0>(tt),i,a[i]);
    tup t1=make_tuple(get<1>(tt),i,a[i]);
    q.push(t0);
    q.push(t1);
  }
  cout<<sum<<endl;
  return 0;
}