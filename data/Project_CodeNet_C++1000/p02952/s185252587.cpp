#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    int cnt = 1;
    int now = 10;
    int n = N;
    int ans = 0;
    while(n / now != 0){
        if(cnt % 2 == 1){
            int x = pow(10,cnt) - pow(10,cnt-1);
            ans += x;
        }
        cnt++;
        now *= 10;
    }
    if(cnt % 2 == 1){
        int x = N - pow(10,cnt-1) + 1;
        ans += x;
    }

    cout << ans << endl;

    return 0;
}