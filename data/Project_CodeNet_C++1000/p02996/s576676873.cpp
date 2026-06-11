#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  vector<vector<ll>> v;
  for(int i=0;i<n;i++){
    ll a,b;
    cin >> a >> b;
    v.push_back({b,a});
  }
  sort(v.begin(),v.end());
  ll s=0;
  bool kanou=true;
  for(int i=0;i<n;i++){
    s+=v[i][1];
    if(s<=v[i][0]);
    else{
      kanou=false;
      break;
    }
  }

  if(kanou)cout << "Yes" << endl;
  else cout << "No" << endl;



}