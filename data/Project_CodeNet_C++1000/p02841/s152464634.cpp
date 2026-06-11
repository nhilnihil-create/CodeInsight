#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

const int mx = 100005;
int dp[6][mx];

int main(){
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    cout << static_cast<int>(m1!=m2) << endl;
    
    return 0;
}
