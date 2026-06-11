#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N,M;
    cin >> N >> M;
    vector<long long>a(N);
    long long cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]/=2;
        if(i == 0) {
            cnt = a[i];
            continue;
        }
        cnt = cnt/__gcd(cnt,a[i])*a[i];
        if(cnt > M) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < N; i++) {
        if(cnt/a[i]%2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (M-cnt)/(cnt*2)+1LL << endl;
}