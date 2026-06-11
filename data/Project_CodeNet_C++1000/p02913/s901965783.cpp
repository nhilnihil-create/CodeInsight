#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;

const long long MOD = 1000000007;
const long long B = 17777771;

int N;
string S;

template<typename T,T MOD,T B>
struct RollingHash{
  vector<T> hash,p;
  RollingHash(){}
  RollingHash(const string &s){
    int n=s.size();
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=(hash[i]*B+s[i])%MOD;
      p[i+1]=p[i]*B%MOD;
    }
  }
  //S[l, r)
  T find(int l,int r){
    T res=hash[r]+MOD-hash[l]*p[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
};

bool isOk(int key, RollingHash<long long, MOD, B> r) {
  bool f = true;
  if(key == 0) {
    return f;
  }
  rep(i, N - key + 1) {
    string temp = S.substr(i, key);
    // cout << key << " " << temp << endl;
    int cnt = 0;
    for(int j = i+key; j < N - key + 1; j++) {
      if(r.find(j, j+key) == r.find(i, i + key)) {
        if(S.substr(j, key) == S.substr(i, key)) {
          cnt++;
          // cout << cnt << endl;
        }
      }
    }
    if(cnt >= 1) {
      f = false;
      break;
    }
  }
  return f;
}

int lower_search(RollingHash<long long, MOD, B> R) {
  int l = 0, r = N / 2 + 1;
  while(r - l > 1) {
    int half = (r + l) / 2;
    // cout << "half " << half << endl;
    if(isOk(half, R)) r = half;
    else l = half;
  }
  return r;
}

int main() {
  cin >> N >> S;
  RollingHash<long long, MOD, B> r(S);
  int ans = 0;
  ans = lower_search(r);
  cout << ans - 1 << endl;
  return 0;
}