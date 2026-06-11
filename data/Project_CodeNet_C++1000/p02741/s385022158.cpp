#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf  = 1e7+5;

bool visited [inf];
int dist[inf];
int main() {
  vector<int> vec = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int k; cin >>k;
  cout << vec[k-1];
}

