#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

vector<string> r(string in, int max) {
  vector<string> result;

  if (in.size() == max) {
    result.emplace_back(in);
    return result;
  }

  char last = in[in.size() - 1];

  char char_to = 'a';
  for (ll i = 0; i < in.size(); i++) {
    if (in[i] > char_to) {
      char_to = in[i];
    }
  }
  char_to++;

  char cur = 'a';
  for (;;) {
    auto plus = r(in + cur, max);
    for (auto e : plus) {
      result.emplace_back(e);
    }
    if (cur == char_to) {
      break;
    }
    cur += 1;
  }

  // auto plus1 = r(in + last, max);
  // for (auto e : plus1) {
  //   result.emplace_back(e);
  // }

  // auto plus2 = r(in + char(last + 1), max);
  // for (auto e : plus2) {
  //   result.emplace_back(e);
  // }

  // if (last > 'a') {
  //   auto plus3 = r(in + char(last - 1), max);
  //   for (auto e : plus3) {
  //     result.emplace_back(e);
  //   }
  // }

  return result;
}

int main() {
  ll N;
  scanf("%lld", &N);

  vector<string> list = r("a", N);

  sort(list.begin(), list.end());

  for (ll i = 0; i < list.size(); i++) {
    cout << list[i] << endl;
  }
}

/*
aaa
abc
abb
acc
*/