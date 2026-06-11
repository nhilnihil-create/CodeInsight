#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int K, A, B;
    cin >> K >> A >> B;

    int v = K * (A / K);
    bool ok = false;
    while (v <= B) {
        if (A <= v && v <= B) {
            ok = true;
            break;
        }
        v += K;
    }
    if (ok) {
        cout << "OK" << endl;
    }
    else {
        cout << "NG" << endl;
    }

    return 0;
}