#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int D1, D2, cnt = 0;
    bool is_ok = false;
    for (int i = 0; i < N; i++) {
        cin >> D1 >> D2;
        if (D1 == D2) cnt++;
        else if (D1 != D2 && cnt != 0) cnt = 0;
        if (cnt == 3) {
            is_ok = true;
            break;
        }
    }
    if (is_ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}