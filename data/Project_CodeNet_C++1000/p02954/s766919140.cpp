#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string S;

void solve() {
    cin >> S;
    int N = S.size();
    vector<int> a(N, 0);
    int i = 0;
    while(i < N - 1) {
        char cr = S[i];
        char cl = S[i+1];
        if (!(cr == 'R' && cl == 'L')) {
            i++;
            continue;
        }
        a[i]++; a[i+1]++;
        int ir = 1;
        while (S[i-ir] == 'R' && 0 <= i - ir) {
            if (ir % 2 == 0) a[i]++;
            else a[i+1]++;
            ir++;
        }
        int il = 1;
        while (S[i+1 + il] == 'L' && i+1+il < N) {
            if (il % 2 == 0) a[i+1]++;
            else a[i]++;
            il++;
        }
        i = i+1+il;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}

