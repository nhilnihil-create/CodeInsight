#include <iostream>

using namespace std;

int main(void)
{
    int N;

    cin >> N;

    int cnt = 0;
    bool f = false;
    for (int i = 0; i < N; i++) {
        int D1, D2;
        cin >> D1 >> D2;
        if (D1 == D2) {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt == 3) {
            f = true;
        }
    }
    if (f) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}