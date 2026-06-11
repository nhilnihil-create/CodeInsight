#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> freq(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int p; cin >> p;
        freq[p]++;
    }
    for (int i = 1; i <= N; ++i) {
        cout << freq[i] << "\n";
    }
}