#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI 3.141592653
#define rep(i, k, n) for(ll i = k; i < n; i++)



int main(){
  ll k; cin >> k;
  string s; cin >> s;
  ll p = s.size();

  rep(i, 0, min(k, p)){
    cout << s[i];
  }

  if(s.size() > k){cout << "..." << endl;}
}
