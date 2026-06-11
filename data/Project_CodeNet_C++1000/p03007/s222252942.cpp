#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.rbegin(), A.rend());
    vector<pair<long long, long long>> S;

    for(int i = 1; i < N-1; i++) {
        if(A[i] >= 0) {
            S.push_back(make_pair(A[N-1], A[i]));
            A[N-1] -= A[i];
        } else {
            S.push_back(make_pair(A[0], A[i]));
            A[0] -= A[i];
        }
    }
    S.push_back(make_pair(A[0], A[N-1]));
    A[0] -= A[N-1];
    cout << A[0] << endl;
    for(pair<int, int> p: S) {
        cout << p.first << " " << p.second << endl;
    }
}