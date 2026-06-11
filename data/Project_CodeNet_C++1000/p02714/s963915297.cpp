#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> s(N);
    rep(i, N) {
        char c;
        cin >> c;
        if (c == 'R') s[i] = 0;
        if (c == 'G') s[i] = 1;
        if (c == 'B') s[i] = 2;
    }

    int count[3] = {0};
    ll sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        switch (s[i]) {
        case 0:
            count[0]++;
            sum += count[1] * count[2];
            break;
        case 1:
            count[1]++;
            sum += count[0] * count[2];
            break;
        case 2:
            count[2]++;
            sum += count[0] * count[1];
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int k = j + j - i;
            if (k >= N) break;
            if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) sum--;
        }   
    }
    cout << sum << endl;
    return 0;
}
