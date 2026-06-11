#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    int x = (int) (n / 1.08);

    if (((int) (x * 1.08)) != n && ((int) ((x + 1) * 1.08)) != n) {
        cout << ":(" << endl;
    } else {
        if ((int) (x * 1.08) == n) {
            cout << x << endl;
        } else {
            cout << ++x << endl;
        }
    }
}