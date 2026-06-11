#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        A[x-1] = i + 1;
    }
    for(int i=0; i<N; i++) {
        cout << A[i] << " ";
    }

}