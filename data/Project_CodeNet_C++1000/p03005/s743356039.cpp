#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    if (K == 1) cout << 0 << endl;
    else {
        int mi = 1;
        int ma = N-(K-1);
        cout << ma-mi << endl;
    }
}
