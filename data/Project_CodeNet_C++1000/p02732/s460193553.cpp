#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

ll c2(ll x)
{
  return x*(x-1)/2;
}

int main(){
  int n;cin>>n;
  vector<int> a(n);
  map<int,ll> mp1;
  for (auto &&i : a)
  {
    cin >> i;
    mp1[i]++;
  }
  vector<ll> ans;
  ll calc = 0;
  for (auto &&i : mp1)
  {
    calc += c2(i.second);
  }
  

  for (auto &&i : a)
  {
    ll tmp = calc;
    tmp -= mp1[i] - 1;
    ans.push_back(tmp);
  }
  for (auto &&i : ans)
  {
    cout << i << endl;
  }
  
}
