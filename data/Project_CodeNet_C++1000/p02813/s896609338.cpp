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
    int p, q;
    p = q = 0;
    for (int i = n - 1; i >= 0; i--) {
        int temp;
        cin >> temp;
        p += temp * pow(10, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp;
        cin >> temp;
        q += temp * pow(10, i);
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int b_size = fac(n);
    int b[b_size] = {};
    int i = 0;
    do {
        for (int j = 0; j < n; j++) {
            b[i] += a[j] * pow(10, j);
        }
        i++;
    } while (next_permutation(a, a + n));

    sort(b, b + b_size);

    int a_pos = distance(b, lower_bound(b, b + b_size, p));
    int b_pos = distance(b, lower_bound(b, b + b_size, q));
    
    cout << abs(a_pos - b_pos) << endl;

    return 0;
}