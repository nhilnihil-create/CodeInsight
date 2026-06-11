#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e17;
const ll MOD = 1e9+7;

int main() {
    // input, ready
    int N,K,C;
    string S;
    cin >> N >> K >> C;
    cin >> S;
    vector<bool> entry(N);
    int cnt = 0;
    for (auto s: S) {
      if (s == 'o') entry[cnt] = true;
      else entry[cnt] = false;
      cnt++;
    }

    // resolve
    vector<int> left(N);
    vector<int> right(N);
    for (int i=0; i<N; i++) {
      left[i] = 0;
      right[i] = 0;
    }
    int k = 0;
    int c = C;
    for (int i=0; i<N; i++) {
      if (entry[i] && C <= c) {
        k++;
        left[i] = k;
        c = 0;
      }
      else {
        left[i] = 0;
        c++;
      }
      if (k >= K) break;
    }

    k = K;
    c = C;
    for (int i=N-1; i>=0; i--) {
      if (entry[i] && C <= c) {
        right[i] = k;
        k--;
        c = 0;
      }
      else {
        right[i] = 0;
        c++;
      }
      if (k <= 0) break;
    }    

    // output
    for (int i=0; i<N; i++) {
      if (left[i] == right[i] && left[i] > 0) cout << i+1 << endl;
    }

    return 0;
}
