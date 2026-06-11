#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;
typedef long long ll;

int main() {

    int H1, H2, M1, M2, K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;

    int ans = 0;
    ans += (H2 - H1) * 60;
    ans += M2 - M1;

    cout << ans - K << endl;
    
    return 0;
}