#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int N;
    cin >> N;
    vector<int>A(1+N);
    vector<int>B(1+N);
    for(int i = 0; i <= N; i++) {
        cin >> A[i];
    }
    B[N] = 0;
    for(int i = N; i > 0; i--) {
        B[i-1] = B[i]+A[i];
    }
    int ans = 0;
    int cnt = 1;
    for(int i = 0; i <= N; i++) {
        ans+=cnt;
        cnt-=A[i];
        if(cnt < 0) {
            ans = -1;
            break;
        }
        cnt*=2;
        cnt = min(cnt,B[i]);
    }
    cout << ans << endl;
}