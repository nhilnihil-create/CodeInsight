#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W,N;
    cin >> H >> W >> N;

    int ans;
    ans = ceil(N/float(max(H,W)));

    cout << ans << endl;

    return 0;
}
