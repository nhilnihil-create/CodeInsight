#include <bits/stdc++.h>
using namespace std;

bool checkBegin(int N, vector<int> a) {
    map<int, int> ch;
    for (int i = 0; i < N; i++) ch[a[i]]++;
    if (ch.count(1)) return true;
    else return false;
}

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    if (!checkBegin(N, a)) {
        cout << "-1" << endl;
        return 0;
    }

    int res = 0, j = 1;
    for (int i = 0; i < N; i++) {
        if (a.at(i) == j) {
            j++; continue;
        }
        else res++;
    }
    cout << res << endl;
}