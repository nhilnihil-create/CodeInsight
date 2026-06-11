#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    int n = 1;
    while(true) {
        if((n * x) % 360 == 0) {
            cout << n << "\n";
            break;
        } else {
            n++;
        }
    }
    return 0;
}
