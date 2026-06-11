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
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if ( m2 == m1 ) cout << 0 << endl;
    else            cout << 1 << endl;
    return 0;
}
