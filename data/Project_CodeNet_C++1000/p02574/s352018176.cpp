#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_A = 1000005;

int main() {
    int N; cin >> N;
    vector<int> A(N), C(MAX_A);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[A[i]]++;
    }
    
    bool pairwise = true;;
    for (int i = 2; i < MAX_A; i++) {
        int cnt = 0;
        for (int j = i; j < MAX_A; j+=i) {
            cnt += C[j];
        }
        if (cnt > 1) {
            pairwise = false;
            break;
        }
    }
    if (pairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int g = 0;
    for (int i = 0; i < N; i++) g = __gcd(g, A[i]);
    if (g == 1) {
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;
    return 0;
}