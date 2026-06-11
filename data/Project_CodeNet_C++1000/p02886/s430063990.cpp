#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> d(N, 0);
    int recover = 0;
    for (auto &x: d) cin >> x;
    for (size_t i=0; i<d.size(); i++) {
        for (size_t j=(i+1); j<d.size(); j++) {
            recover += d[i] * d[j];
        }
    }
    cout << recover << endl;
    return 0;
}

