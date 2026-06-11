#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  vector<pair<ll,ll>> a;
  for(int i=0;i<n;i++){
    ll b;
    cin >>b;
    a.push_back(make_pair(b,i+1));
  }

  sort(a.begin(),a.end());
  for(int i=1;i<n+1;i++){
    if(a[n-1].second==i)cout << a[n-2].first << endl;
    else cout << a[n-1].first << endl;
  }

}