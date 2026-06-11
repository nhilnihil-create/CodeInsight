#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
  
    for (int i = 0; i < N; i++) cin >> P.at(i), P.at(i)--;
    for (int i = 0; i < N; i++) cin >> Q.at(i), Q.at(i)--;

    vector<int> V(N);
    map<vector<int>, int> A;
    int cnt = 0;
    for (int i = 0; i < N; i++) V.at(i) = i;

    do {
        A[V] = cnt++;
    } while (next_permutation(V.begin(), V.end()));

    cout << abs(A[P] - A[Q]) << endl;
}