#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { return (a%b == 0) ? b : gcd(b, a%b); }
inline int fac(int n) { return (n==0) ? 1 : n * fac(n - 1); }

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int a_pos = -1, b_pos = -1;
    int n_fac = fac(n);
    for (int i = 0; i < n_fac; i++)
    {
        if (a == p)
        {
            a_pos = i;
        }
        if (a == q)
        {
            b_pos = i;
        }
        if (a_pos != -1 && b_pos != -1)
        {
            break;
        }
        else
        {
            next_permutation(a.begin(), a.end());
        }
    }

    cout << abs(a_pos - b_pos) << endl;

    return 0;
}