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

    int X;
    cin >> X;
    int K = 0;
    int d = 0;
    while (true) {
        d += X;
        d %= 360;
        K++;
        if (d == 0) break;
    }

    cout << K << endl;
    
    return 0;
}