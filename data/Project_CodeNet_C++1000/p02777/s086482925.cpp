#include <bits/stdc++.h>

typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout << i << endl;
#define AS(i) cout << i << " ";

const int INF = 1001001001;

using namespace std;

int main() {

    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;

    if (s == u)
        a--;
    if (t == u)
        b--;

    AA(a << ' ' << b);
}
