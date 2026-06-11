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
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for ( int i = 1; i <= m; ++i ) {
        for ( int j = 1; j <= d; ++j ) {
            if ( ( j % 10 >= 2 ) && ( j / 10 >= 2 ) && ( j % 10 ) * ( j / 10 ) == i ) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
