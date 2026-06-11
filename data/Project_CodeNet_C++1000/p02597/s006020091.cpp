#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    string c;
    cin >> c;

    int rnum = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == 'R') rnum++;
    }

    int res = 0;
    for (int i = 0; i < rnum; ++i) {
        if (c[i] == 'W') res++;
    }
    cout << res << endl;
}