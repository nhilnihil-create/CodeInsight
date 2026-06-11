#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> an(N);
    for (int i = 0; i < N; i++) {
        cin >> an[i];
    }
    sort(an.begin(), an.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 && an[i] > 0) ans -= an[0];
        else if (i == N-1 && an[i] < 0) ans += an[N-1];
        else ans += abs(an[i]);
    }
    cout << ans << endl;
    for (int i = N-2; an[i] >= 0 && i > 0; i--) {
        cout << an[0] << " " << an[i] << endl;
        an[0] -= an[i];
    }
    for (int i = 1; an[i] < 0 && i < N-1; i++) {
        cout << an[N-1] << " " << an[i] << endl;
        an[N-1] -= an[i];
    }
    cout << an[N-1] << " " << an[0] << endl;
}
