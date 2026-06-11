#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }

const int maxn = 1e6 + 11;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h1,m1;
    int h2,m2;
    int k;

    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> k;

    int tot = 60*(h2-h1);
    tot -= m1;
    tot += m2;

    tot -= k;

    out(tot);
    
    
    
    return 0;
}
