#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;

int main() {
    string S;
  cin >> S;
  ll sum = 0;
  for(auto c : S) {
    sum += (ll)(c - '0');
  }
    if(sum % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
