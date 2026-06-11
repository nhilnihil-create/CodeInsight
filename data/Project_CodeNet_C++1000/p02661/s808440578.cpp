#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for(int in=0;in<n;in++) {
        cin >> a[in] >> b[in];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans, mid, mid1, mid2;
    if(n%2==1) {
        mid = n / 2;
        ans = b[mid] - a[mid] + 1; 
    }
    else {
        mid2 = n / 2;
        mid1 = mid2 - 1;
        int aa, bb;
        aa = a[mid2]+a[mid1];
        bb = b[mid2]+b[mid1];
        ans = bb - aa + 1;
    }
    cout << ans << endl;
    return 0;
}
