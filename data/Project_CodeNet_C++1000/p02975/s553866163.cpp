#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    int A[N];
    map<int, int> cnt;
    for (int i = 0; i < N; i++) { 
        cin >> A[i];
        cnt[A[i]]++;
    }
    if (cnt[0] == N) {
        cout << "Yes" << endl;
        return 0;
    }
    if (N % 3 != 0) {
        cout << "No" << endl;
        return 0;
    }
    vector<int> all;
    for (auto p : cnt) {
        for (int i = 0; i < p.second / (N / 3); i++) {
            all.push_back(p.first);
        }
    }
    if (all.size() == 3 && (all[0] ^ all[1] ^ all[2]) == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}