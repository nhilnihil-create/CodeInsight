#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  ll k;

  cin >> s >> k;

  ll left = 0;
  ll right = 0;
  vector<ll> clusters;

  int n = s.size();

  int i = 0;
  while (i < n) {
    int j = i;
    while (j + 1 < n && s[j + 1] == s[i]) j++;
    clusters.push_back(j - i + 1);
    i = j + 1;
  }


  if (clusters.size() == 1) {
    ll len = clusters[0] * k;
    cout << len / 2 << endl;
    return 0;
  }

  ll result = 0;
  if (s[0] != s[n - 1]) {
    for (ll c : clusters) {
      result += c / 2 * k;
    }
  } else {
    result += clusters[0] / 2 + clusters.back() / 2;
    result += (clusters[0] + clusters.back()) / 2 * (k - 1);
    for (int i = 1; i < clusters.size() - 1; ++i) {
      result += clusters[i] / 2 * k;
    }
  }

  cout << result << endl;

  return 0;
}
