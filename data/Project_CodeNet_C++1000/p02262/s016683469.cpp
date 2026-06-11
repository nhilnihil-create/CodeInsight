#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

long long cnt;
int A[1000000];
vector<int> G;

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(int A[], int n) {
    for (int h = 1;;) {
        if (h > n) break;
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    REP(i, n) cin >> A[i];
    cnt = 0;
    shellSort(A, n);

    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        cout << G[i];
        if (i != 0) cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
    REP(i, n) cout << A[i] << endl;
    return 0;
}