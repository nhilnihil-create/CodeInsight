#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

vector<pair<ll,ll>> output;
void process(ll x,ll y,vector<ll>& vec_x,vector<ll>& vec_y,vector<ll>& tgt) {
  output.push_back({x,y});
  auto itr_x=lower_bound(vec_x.begin(), vec_x.end(),x);
  vec_x.erase(itr_x);
  auto itr_y=lower_bound(vec_y.begin(), vec_y.end(),y);
  vec_y.erase(itr_y);
  // tgt.push_back(x-y);
  tgt.insert(tgt.begin(),x-y);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin>>n;
  if (n==2) {
    vector<ll> tmp(2);
    cin>>tmp[0]>>tmp[1];
    sort(tmp.begin(), tmp.end());
    cout<<tmp[1]-tmp[0]<<endl;
    cout<<tmp[1]<<" "<<tmp[0]<<endl;
    return 0;
  }
  vector<ll> plus,minus;
  for (ll i = 0; i < n; ++i)
  {
    ll a;
    cin>>a;
    if (a>0) plus.push_back(a);
    else minus.push_back(a);
  }

  sort(plus.begin(), plus.end());
  sort(minus.begin(), minus.end());

  if (minus.empty()) {
    process(plus.front(),plus.back(),plus,plus,minus);
  } else if (plus.empty()) {
    process(minus.back(),minus.front(),minus,minus,plus);
  }

  // while (minus.size()!=1) {
  //   process(plus.back(),minus.front(),plus,minus,plus);
  // }

  // while (plus.empty()!=1) {
  //   process(minus.front(),plus.front(),minus,plus,minus);
  // }

  // process(plus.front(),minus.front(),plus,minus,plus);

  while (plus.size()!=1) {
    process(minus.front(),plus.front(),minus,plus,minus);
  }


  while (!minus.empty()) {
    process(plus.front(),minus.front(),plus,minus,plus);
  }


  cout<<plus.front()<<endl;
  for (ll i = 0; i < output.size(); ++i)
  {
    cout<<output[i].first<<" "<<output[i].second<<endl;
  }
}