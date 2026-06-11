#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }


vector<LL> zalgorithm(string& S){
    vector<LL> A(S.size());
    A[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
      while (i+j < S.size() && S[j] == S[i+j]) ++j;
      A[i] = j;
      if (j == 0) { ++i; continue;}
      int k = 1;
      while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
      i += k; j -= k;
    }
    return A;
}

int main(){
    LL n;
    cin >> n;
    string s;
    cin >> s;
    LL ans = 0;
    for(LL i = 0; i < n; ++i){
        string s2 = s.substr(i);
        vector<LL> a = zalgorithm(s2);
        for(LL j = 1; j < a.size(); ++j){
            ans = max(ans, min(j, a[j]));
        }
    }
    cout << ans << endl;
    return 0;
}

