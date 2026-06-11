#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    bool exist = false;
    for (int i = 0; i < N; i++) {
        int D1, D2; cin >> D1 >> D2;
        if (D1 == D2) {
            ans++;
        } else {
            ans = 0;
        }
        if (ans == 3) {
            exist = true;
        }
    }
    if (exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
