#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    string U = "";
    for (int i = 0; i < N; i++)
    {
        U += S[i];
        U += T[i];
    }
    cout << U << endl;
  return 0;
}
