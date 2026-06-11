#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;

    bool res = false;
    rep(i, 10) rep(j, 10) if(i * j == N) res = true;

    if(res == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
