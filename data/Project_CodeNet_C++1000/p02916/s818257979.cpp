#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<numeric>
#include<stack>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
const double PI = acos(-1);  // PI = 3.141593...

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    for(int i=0; i<n-1; ++i) cin >> c[i];

    int ans = b[a[0]-1];
    for(int i = 1; i < n; ++i) {
        ans += b[a[i]-1];
        if(a[i] == a[i-1] + 1) {
            ans += c[a[i-1]-1];
        }
    }
    cout << ans << endl;
    return 0;
}