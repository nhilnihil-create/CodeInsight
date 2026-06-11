#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  if(N == 2) {
    vector<ll> as(N);
    for(int i = 0; i < N; ++i) {
      cin >> as[i];
    }
    sort(as.begin(), as.end());
    cout << as[1] - as[0] << endl;
    cout << as[1] << " " << as[0] << endl;
    return 0;
  }

  vector<ll> pas;
  vector<ll> nas;
  {
    int a;
    for(int i = 0; i < N; ++i) {
      cin >> a;
      if(a >= 0) {
        pas.push_back(a);
      } else {
        nas.push_back(a);
      }
    }
  }
  sort(pas.begin(), pas.end());
  sort(nas.begin(), nas.end());

  vector<pair<ll, ll>> log;

  if(pas.size() == 0) { // negativeしかない場合
    auto mx = nas.back();
    nas.pop_back();
    auto mn = nas.front();
    nas.erase(nas.begin());

    log.push_back(make_pair(mx, mn));
    pas.push_back(mx - mn);
  } else if(nas.size() == 0) { // positiveしかない
    auto mn = pas.front();
    pas.erase(pas.begin());
    auto mx = pas.back();
    pas.pop_back();

    log.push_back(make_pair(mn, mx));
    nas.push_back(mn - mx);
  }

  // positiveが１個になるまでnegative化する
  while(pas.size() > 1) {
    auto p = pas.back();
    pas.pop_back(); // 末尾を消す
    auto n = nas.back();
    nas.pop_back();

    log.push_back(make_pair(n, p));
    nas.push_back(n - p); //
  }
  // negativeがなくなるまでpositive化する
  while(nas.size() > 0) {
    auto p = pas.back();
    pas.pop_back();
    auto n = nas.back();
    nas.pop_back();

    log.push_back(make_pair(p, n));
    pas.push_back(p - n);
  }

  cout << pas.front() << endl;
  for(auto l : log) {
    cout << l.first << " " << l.second << endl;
  }
  return 0;
}