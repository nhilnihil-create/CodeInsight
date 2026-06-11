#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    vector<int> children(N);
    int i = 0;
    while (i < N) {
        int j = i;
        while (S[j] != 'L' && j < N) j++;
        int r = j - 1, l = j;
        while (S[j] != 'R' && j < N) j++;
        int cnt = j - i;
        if (cnt % 2 == 0) {
            children[r] = children[l] = cnt / 2;
        } else {
            int cntR = l - i, cntL = j - l;
            if (cntR > cntL) {
                children[l] = cnt / 2;
                children[r] = cnt - children[l];
                if (cntR % 2 == 0) swap(children[r], children[l]);
            } else {
                children[r] = cnt / 2;
                children[l] = cnt - children[r];
                if (cntL % 2 == 0) swap(children[r], children[l]);
            }
        }
        i = j;
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << children[i];
    }
    cout << endl;
}