#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    if (N % 10 == 7) {
        cout << "Yes" << endl;
        return 0;
    }
    N /= 10;
    if (N % 10 == 7) {
        cout << "Yes" << endl;
        return 0;
    }
    N /= 10;
    if (N % 10 == 7) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}
