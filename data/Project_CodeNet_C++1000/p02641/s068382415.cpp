#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int X, N;
    cin >> X >> N;
    
    vector<bool> p(N + 100, false);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        p[a] = true;
    }

    for (int i = 0; ; i++) {
        if (X - i < 0) {
            cout << X - i << endl;
            break;
        }
        else if (p[X - i] == false) {
            cout << X - i << endl;
            break;
        }
        else if (p[X + i] == false) {
            cout << X + i << endl;
            break;
        }
    }
}