#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll X,Y,A,B,C;
  cin>>X>>Y>>A>>B>>C;
  vector<ll> p(A);
  vector<ll> q(B);
  vector<ll> r(C);
  for(ll i=0;i<A;++i){
    cin>>p.at(i);
  }
  for(ll i=0;i<B;++i){
    cin>>q.at(i);
  }
  for(ll i=0;i<C;++i){
    cin>>r.at(i);
  }
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  sort(r.begin(),r.end());
  vector<ll> ans(0);
  ll answer=0;
  for(ll i=0;i<X;++i){
    ans.push_back(p.at(A-i-1));
    answer+=p.at(A-i-1);
  }
  for(ll i=0;i<Y;++i){
    ans.push_back(q.at(B-i-1));
    answer+=q.at(B-i-1);
  }
  sort(ans.begin(),ans.end());
  for(ll i=0;i<C;++i){
    if(i<X+Y){
      if(ans.at(i)<r.at(C-i-1)){
        answer+=r.at(C-i-1);
        answer-=ans.at(i);
      }
    }
  }
  cout<<answer<<endl;
}