#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    string S;
    cin >> N >> S;
    if (N % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    if (S.substr(0, N / 2) == S.substr(N / 2)) cout << "Yes" << endl;
    else cout << "No" << endl;




    return 0;
}