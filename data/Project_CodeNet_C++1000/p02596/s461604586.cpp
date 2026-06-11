#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;
const double PI = acos(-1.0);

int main() {
    
    int K;
    cin >> K;

    int a[1000001];
    a[1] = 7 % K;
    for(int i = 2; i <= K; i++) a[i] = (10*a[i-1] + 7) % K;

    int ans = -1;

    for(int i = 1; i <= K; i++) {
        if(a[i] == 0) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}
