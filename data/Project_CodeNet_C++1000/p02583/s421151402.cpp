#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define square(x) pow(x,2.0)
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define max_queue(x) priority_queue<x>
#define min_queue(x) priority_queue<x, vector<x>, greater<x>>
#define big_sort(v) sort(all(v), [](int a, int b) { return a > b; })//大きい順にソート
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
using vd = vector<long double>;
#define co(x) cout << x << endl;
#define cins(n,v) rep(i,n){cin >> v.at(i);}
#define couts(v) rep(i,v.size()){cout << v.at(i) << endl;}
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
/*
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
*/
int main() {
  int n,num=0;
  cin >> n;
  vector<int> v(n);
  rep(i,n){
    cin >> v[i];
  }
  rep(i, n-2){
    REP(j,i+1, n-1){
      REP(k,j+1,n){
        if(v[i]==v[j]||v[i]==v[k]||v[j]==v[k]){}
        else{
          if(v[i]+v[j]>v[k]&&v[i]+v[k]>v[j]&&v[k]+v[j]>v[i]){
            num++;
          }
        }
      }
    }
  }
  cout << num << endl;
  return 0;
}
