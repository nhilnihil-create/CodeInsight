#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};



int N;

int main () {
  vector<int> v_plus;
  vector<int> v_minus;

  cin >> N;
  rep(i, N) {
    int tmp;
    cin >> tmp;

    if (tmp < 0) v_minus.push_back(tmp);
    else v_plus.push_back(tmp);
  }

  if (v_minus.size() == N) {
    sort(All(v_minus), greater<int>());

    ll tmp_l = v_minus[0];

    Rep(i, N-1) {
      ll tmp_r = v_minus[i+1];
      tmp_l -= tmp_r;
    }

    cout << tmp_l << "\n";

    tmp_l = v_minus[0];
    Rep(i, N-1) {
      ll tmp_r = v_minus[i+1];
      cout << tmp_l << " " << tmp_r << "\n";
      tmp_l -= tmp_r;
    }
  } else if (v_plus.size() == N) {
    sort(All(v_plus));

    ll tmp_l = v_plus[0];

    Rep(i, N-2) {
      ll tmp_r = v_plus[i+1];
      tmp_l -= tmp_r;
    }

    cout << v_plus[N-1] - tmp_l << "\n";

    tmp_l = v_plus[0];

    Rep(i, N-2) {
      ll tmp_r = v_plus[i+1];
      cout << tmp_l << " " << tmp_r << "\n";
      tmp_l -= tmp_r;
    }

    cout << v_plus[N-1] << " " <<  tmp_l << "\n";
  } else {
    int p = v_plus.size();

    ll tmp = v_minus[0];
    Rep(i, p-1) {
      tmp -= v_plus[i+1];
    }

    tmp = v_plus[0] - tmp;

    for (int i=p;i<N-1;++i) {
      tmp -= v_minus[i-p+1];
    }

    cout << tmp << "\n";

    tmp = v_minus[0];
    Rep(i, p-1) {
      cout << tmp << " " << v_plus[i+1] << "\n";
      tmp -= v_plus[i+1];
    }

    cout << v_plus[0] << " " << tmp << "\n";

    tmp = v_plus[0] - tmp;

    for (int i=p;i<N-1;++i) {
      cout << tmp << " " << v_minus[i-p+1] << "\n";
      tmp -= v_minus[i-p+1];
    }
  }
}