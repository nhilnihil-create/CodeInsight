#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<pair<int, int>> op;
    if (A[0] <= 0) {
        int pos = N-2;
        while (A[pos] > 0) {
            op.push_back({A[0], A[pos]});
            A[0] -= A[pos];
            pos--;
        }
        for (int i = pos; i >= 0; i--) {
            op.push_back({A[N-1], A[i]});
            A[N-1] -= A[i];
        }
        cout << A[N-1] << endl;
        for (pair<int, int> p : op) printf("%d %d\n", p.first, p.second);
    }
    else {
        for (int i = 1; i <= N-2; i++) {
            op.push_back({A[0], A[i]});
            A[0] -= A[i];
        }
        op.push_back({A[N-1], A[0]});
        A[N-1] -= A[0];
        cout << A[N-1] << endl;
        for (pair<int, int> p : op) printf("%d %d\n", p.first, p.second);
    }
    return 0;
}