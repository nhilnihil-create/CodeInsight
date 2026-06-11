#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> a(9);
    for (int i = 0; i < 9; i++) {
        cin >> a.at(i);
    }
    int n;
    cin >> n;
    int b = 0;
    for (int i = 0; i < n; i++) {
        int bi;
        cin >> bi;
        for (int i = 0; i < 9; i++) {
            if (a.at(i) == bi) {
                b |= 1 << i;
            }
        }
    }
    if ((b & 448) == 448)
        cout << "Yes" << endl;
    else if ((b & 56) == 56)
        cout << "Yes" << endl;
    else if ((b & 7) == 7)
        cout << "Yes" << endl;
    else if ((b & 292) == 292)
        cout << "Yes" << endl;
    else if ((b & 146) == 146)
        cout << "Yes" << endl;
    else if ((b & 73) == 73)
        cout << "Yes" << endl;
    else if ((b & 273) == 273)
        cout << "Yes" << endl;
    else if ((b & 84) == 84)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}