#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;

    int d = max(h,w);
    int ans = (n + d - 1) / d;
    cout << ans << endl;
    return 0;
}