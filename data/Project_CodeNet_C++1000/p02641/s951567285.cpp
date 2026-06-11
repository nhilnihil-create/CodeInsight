#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int N;
bool in_vector(int x, vector<int> vec) {
    for (int i : vec) {
        if (i == x) return false;
    }
    return true;
}

int main() {
    int X; cin >> X >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    int up = 0, down = 1;
    for (int i = 0; i < N + 1; i++) {
        if (i%2 == 0) {
            if (in_vector(X + up, vec)) {
                cout << X + up << endl;
                return 0;
            }
            up++;
        }
        else {
            if (in_vector(X - down, vec)) {
                cout << X - down << endl;
                return 0;
            }
            down++;
        }
    }
}