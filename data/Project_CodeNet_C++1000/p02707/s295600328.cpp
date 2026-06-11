#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> ans(N + 1);
    for (int i = 2; i <= N; i++) {
        cin >> A[i];
        ans[A[i]]++;
    }
    for (int i = 1; i <= N; i++)
        cout << ans[i] << endl;
}