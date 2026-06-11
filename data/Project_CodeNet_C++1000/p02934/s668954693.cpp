#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    long double A[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = 0l;
        cin >> A[i];
    }

    long double sum = 0l;
    for (int i = 0; i < N; i++)
    {
        sum += 1 / A[i];
    }
    cout << setprecision(15) << (long double) 1 / sum << endl;
  return 0;
}
