#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    vector<char> S(N);
    rep(i, N) cin >> S.at(i);

    int cnt = 0;
    rep(i, N) {
        if(S.at(i) == 'A' && i < N - 2)
            if(S.at(i + 1) == 'B')
                if(S.at(i + 2) == 'C') cnt++;
    }
    cout << cnt << endl;
}
