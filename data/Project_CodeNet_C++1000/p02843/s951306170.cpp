#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;


int main() {

    int x;
    cin >> x;
    rep(i,x/100+1) {
        if (100 * i <= x && x <= 105 * i) {
            cout << '1' << endl;
            return 0;
        }
    }
    cout << '0' << endl;
    return 0;
}