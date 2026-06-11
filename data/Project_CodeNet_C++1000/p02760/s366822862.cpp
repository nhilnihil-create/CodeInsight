#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
    int A[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];
    }

    int n;  cin >> n;
    int *b = new int[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(b, b+n);


    bool c[3][3] = {false};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (binary_search(b, b+n, A[i][j]))
                c[i][j] = true;
        }
    }

    bool can = false;
    for (int i = 0; i < 3; i++) {
        if (c[i][1] && c[i][0] && c[i][2])
            can = true;
    }

    for (int i = 0; i < 3; i++) {
        if (c[0][i] && c[1][i] && c[2][i])
            can = true;
    }

    if (c[0][0] && c[1][1] && c[2][2])
        can = true;

    if (c[0][2] && c[1][1] && c[2][0])
        can = true;

    if (can)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;

}