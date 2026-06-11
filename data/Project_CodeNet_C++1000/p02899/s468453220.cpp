#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  vector<vector<ll>> v;
  for(int i=1;i<=n;i++){
    ll a;
    cin >> a;
    v.push_back({a,i});
  }
  sort(v.begin(),v.end());

  for(int i=0;i<n;i++){
    cout << v[i][1] << endl;
  }


}