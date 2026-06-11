#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 2e5+5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;

int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  int n;
  cin >> n;

  map<int,int>mp;
  f(i,0,n){
    int x;  cin >> x;
    mp[x]++;
  }
  if(mp.size() == 1){
    if(mp.begin()->first == 0){
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else if(mp.size() == 2){
    if(n%3 || mp.begin()->second * 3 != n || mp.begin()->first != 0){
      cout << "No\n";
    } else
      cout << "Yes\n";
  }  else if(mp.size() == 3){
    vector<int> v;
    for(auto it : mp){
      if(it.second * 3 != n){
        cout << "No\n";
        return 0;
      }
      v.push_back(it.first);
    }
    if((v[0] ^ v[1]) == v[2])
      cout << "Yes\n";
    else
      cout << "No\n";
  } else cout << "No\n";

  return 0;
}
