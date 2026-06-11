#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,ans=0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (1<=i && i<10) {
            ans++;
        }
        else if (100<=i && i<1000) {
            ans++;
        }
        else if (10000<=i && i<100000) {
            ans++;
        }
    }
    cout << ans << endl;
}