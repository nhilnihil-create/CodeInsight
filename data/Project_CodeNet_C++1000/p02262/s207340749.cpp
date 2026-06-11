#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[1000000];

int cnt;
int m;
vector<int> G;

void isort(int g) {
    for (int i = g; i < N; i++) {
        int v = A[i];
        int j;
        for (j = i - g; j >= 0 && A[j] > v; j -= g) {
            A[j + g] = A[j];
            cnt++;
        }
        A[j + g] = v;
    }
}

void solve() {
    cnt = m = 0;
    for (int i = max(N / 2, 1); i > 0; i /= 2) {
        m++;
        isort(i);
        G.push_back(i);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve();

    cout << m << endl;
    cout << G[0];
    for (int i = 1; i < (int)G.size(); i++) {
        cout << " " << G[i];
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < N; i++) {
        cout << A[i] << endl;
    }
}