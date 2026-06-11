#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    int X, N;
    cin >> X >> N;

    if (N==0) {
        cout << X << endl;
        exit(0);
    }

    vector<int> p(N);
    for (int i=0; i<N; i++) {
        cin >> p[i];
    }

    int ans = 0;
    for (int i=0; i<=100; i++) {
        int judge1=0, judge2=0;

        for (int j=0; j<N; j++) {
            if (X-i==p[j]) {
                judge1 = 1;
                break;
            }
        }
        if (judge1==0) {
            ans = X-i;
            break;
        }

        for (int j=0; j<N; j++) {
            if (X+i==p[j]) {
                judge2 = 1;
                break;
            }
        }
        if (judge2==0) {
            ans = X+i;
            break;
        }

    }

    cout << ans << endl;
    // cout << X << endl;
}