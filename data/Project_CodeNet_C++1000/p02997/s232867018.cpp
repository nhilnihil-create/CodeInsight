#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, k;
  cin >> n >> k;

  if(k > ((n - 1)* (n - 2)) / 2){
    cout << -1 << '\n';
    return 0;
  }

  vector < pair < ll, ll > > p;
  //kaali.
  for(int i = 2; i <= n; i++){
    p.push_back({1, i});
  }
  ll k1 = ((n - 1)* (n - 2)) / 2;
  ll i = 2, j = 3;
  while(k1 > k){
    p.push_back({i,j});
    j++;
    if(j == n + 1){
      i++; j = i + 1;
    }
    k1--;
  }

  cout << p.size() << '\n';
  for(auto i : p) cout << i.first << " " << i.second << '\n';
}
