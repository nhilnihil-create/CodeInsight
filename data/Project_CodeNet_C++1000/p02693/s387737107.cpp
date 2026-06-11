#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int k, a, b;
    cin >> k;
    cin >> a >> b;
    rep(i, b-a+1){
        if((a+i)%k == 0){
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
}