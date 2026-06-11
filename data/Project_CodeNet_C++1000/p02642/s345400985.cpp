#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    vector<int> A;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    vector<bool> divisible(A[N-1] + 1,true);
    int n = 0;
    for (int i = 0; i < N; i++) {
        if (n == A[i]) continue;
        n = A[i];
        if (i < N-1 && A[i] == A[i+1]) {
            divisible[A[i]] = false;
        }
        for (int j = n+n; j < divisible.size(); j += n) {
            divisible[j] = false;
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (divisible[A[i]]) sum +=1;
    }
    cout << sum;
}
