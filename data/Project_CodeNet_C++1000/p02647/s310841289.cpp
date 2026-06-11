#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> a.at(i);
    }

    for ( int ki = 0; ki < K; ki++ ) {
        vector<int> new_a(N+1);
        /* 累積和の準備 */
        for ( int i = 0; i < N; i++ ) {
            int l = max(0, i - a.at(i));
            int r = min(N, i + a.at(i) + 1);
            new_a.at(l)++;
            new_a.at(r)--;
        }
        /* 累積和にする */
        for ( int i = 0; i < N; i++ ) {
            new_a.at(i+1) += new_a.at(i);
        }
        new_a.pop_back(); // 不要な末尾を消す
        /* a と b が同一のとき、全部の電球の強さがマックス */
        if ( a == new_a )
            break;
        a = new_a;
    }

    for ( int i = 0; i < N; i++ ) {
        cout << a.at(i);
        if ( i != N-1 )
            cout << " ";
    }
    cout << endl;

    return 0;
}
