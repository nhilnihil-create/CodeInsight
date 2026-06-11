#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int h, w, n, cnt = 0;
    cin >> h >> w >> n;
    int maxv = max(h, w);
    int minv = min(h, w);
    for (int i = 0; i < minv; i++)
    {
        n -= maxv;
        cnt++;
        if(n <= 0) {
            cout << cnt << endl;
            return 0;
        }
    }
    for (int i = 0; i < maxv; i++)
    {
        n -= minv;
        cnt++;
        if(n <= 0) {
            cout << cnt << endl;
        }
    }
    
    
    return 0;
}