#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll LINF = 1001002003004005006LL;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin  >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    if (n%2==1) {
        int medi = (n+1)/2-1;
        cout << (b[medi]-a[medi]+1) << endl;
    } else {
        int medi1 = n/2-1;
        int medi2 = n/2;
        
        int minm = (a[medi1]+a[medi2]);
        int maxm = (b[medi1]+b[medi2]);
        cout << (maxm-minm+1) << endl;
    }
    return 0;
}