#include <iostream>
#include <vector>
using namespace std;

int main() {
    uint N; cin >> N;
    vector<int> d(N, 0);

    int recover = 0;
    for (auto &x: d) cin >> x;
    for (uint i=0; i<N; i++) {
        for (uint j=(i+1); j<N; j++) {
            recover += d[i] * d[j];
        }
    }
    cout << recover << endl;
    return 0;
}
