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
  ll n; cin >> n;
  ll m = n % 10;
  if(m == 3){cout << "bon" << endl;}
  else if(m == 0 || m == 1 || m == 6 || m == 8){
    cout << "pon" << endl;
  }
  else{cout << "hon" << endl;}
}
