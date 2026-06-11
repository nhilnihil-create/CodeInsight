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
        for (int k = i; k < j; k++) {
            if (k % 2 == r % 2) children[r]++;
            else children[l]++;
        }
        i = j;
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << children[i];
    }
    cout << endl;
}