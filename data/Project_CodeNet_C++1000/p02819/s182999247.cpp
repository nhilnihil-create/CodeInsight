#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {
    int X;
    cin >> X;

    for (int ans = X; ans <= int(1e9); ++ans) {
        bool ng = false;
        // cout << ans << endl;

        for (int i = 2; i <= int(sqrt(X)); ++i) {
            if (ans%i == 0) {
                ng = true;
                break;
            }
        }
        if (ng == false) {
            cout << ans << endl;
            break;
        }
    }

    return 0;
}