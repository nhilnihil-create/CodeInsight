#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, cnt = 0;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        cin >> a;
        V.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (V[i] == V[j] || V[i] == V[k] || V[j] == V[k]) {continue;}
                if ((V[i] + V[j] > V[k]) && (V[i] + V[k] > V[j])  && (V[j] + V[k] > V[i])) {cnt++;}
            }
        }
    }
    cout << cnt << endl;
}
