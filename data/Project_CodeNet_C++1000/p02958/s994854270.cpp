#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    V<int> q = p;
    sort(ALL(q));

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(p[i] != q[i]) cnt++;
    }
    if(cnt == 2 || cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
