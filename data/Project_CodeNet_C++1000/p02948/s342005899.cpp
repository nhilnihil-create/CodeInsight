#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  cin >> n>> m;
  vector<vector<ll>> v;
  for(int i=0;i<n;i++){
    ll a,b;
    cin >> a >> b;
    v.push_back({a,b});
  }
  v.push_back({inf,inf});

  sort(v.begin(),v.end());
  
  priority_queue<ll, vector<ll>, less<ll>> q;

  ll k=0;
  ll s=0,l;
  for(int i=1;i<=m;i++){
    l=0;
    while(v[k][0]<=i){
      q.push(v[k][1]);
      k++;
    }
    if(!q.empty())l=q.top();
    s+=l;
    if(!q.empty())q.pop();
  }

  cout << s << endl;
  
}