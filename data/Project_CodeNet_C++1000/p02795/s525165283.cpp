#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int ans = ( n + max(h, w) - 1 ) / max(h, w);
    cout << ans << endl;
    return 0;
}
