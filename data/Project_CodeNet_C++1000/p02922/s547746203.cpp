#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int A, B; cin >> A >> B;
    int ans = 0;
    int now = 1;
    while(now < B){
        now += A-1;
        ans++;
    }

    cout << ans << endl;

    return 0;
}