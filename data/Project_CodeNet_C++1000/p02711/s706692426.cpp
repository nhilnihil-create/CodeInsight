#include <bits/stdc++.h>
using namespace std;

#define MorsheD ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;

bool mew(int n) {
    while (n) {
        if (n%10 == 7) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main(){
    // ===================
    MorsheD;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ===================

    int n;
    cin >> n;

    if (mew(n)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
