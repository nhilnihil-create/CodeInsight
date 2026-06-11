#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

int main() {
    cin >> N;
    A.resize(N);
    for (int i=0; i<N; i++) cin >> A[i];
    int res = 0;
    for (int i=0; i<A.size(); i++) {
        for (int j=i+1; j<A.size(); j++) {
            res = res + A[i] * A[j];
        }
    }
    cout << res << endl;
    return 0;
}
