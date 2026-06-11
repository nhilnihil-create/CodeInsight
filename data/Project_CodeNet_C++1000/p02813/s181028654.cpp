#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<string> P, Q;

int main() { 
    cin >> N;
    P.resize(N);
    Q.resize(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];
    string X[N];
    for (int i = 1; i <= N; i++) X[i - 1] = to_string(i);
    ll a = 0, b = 0, out = 0, cnt=0;
    string s, p, q;
    do {
      s ="";
      p ="";
      q = "";
      cnt++;
      for (int i = 0; i < N; i++) {
        s += X[i];
        p += P[i];
        q += Q[i];
      }
      if(s==p) a = cnt;
      if (s == q) b = cnt;
    } while (next_permutation(X, X + N));
    
    out = abs(a - b);
    cout << out << endl;
    return 0;
}