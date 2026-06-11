#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll unsigned long long int
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    int sum = 0;
    int h;
    rep(i, N) {
        cin >> h;
        if (h >= K) sum++;
    }

    cout << sum << endl;

    return 0;
}
