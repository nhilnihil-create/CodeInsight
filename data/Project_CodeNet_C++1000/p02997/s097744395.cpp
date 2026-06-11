#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >> k;
  
  ll m=0;
  vector<vector<ll>> v;
  
  if(k>(n-2)*(n-1)/2)cout << -1 << endl;
  else{
    queue<vector<ll>> G;
    for(int i=2;i<n;i++){
      for(int j=i+1;j<=n;j++)G.push({i,j});
    }
    for(int i=2;i<=n;i++){
      v.push_back({1,i});
      m++;
    }
    for(int i=0;i<(n-1)*(n-2)/2-k;i++){
      vector<ll> u=G.front();
      G.pop();
      v.push_back(u);
      m++;
    }
    cout << m << endl;
    for(int i=0;i<m;i++)cout << v[i][0] << " " << v[i][1] << endl;
  }

}