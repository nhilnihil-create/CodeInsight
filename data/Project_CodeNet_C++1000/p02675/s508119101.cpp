#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

int main() {
    string n;
    cin >> n;

    int bon = 3;
    int pon[4] = {0, 1, 6, 8};

    if ((n[n.size() - 1] - '0') == bon) {
        cout << "bon" << endl;
        return 0;
    }

    rep(i, 4) {
        if ((n[n.size() - 1] - '0') == pon[i]) {
            cout << "pon" << endl;
            return 0;
        }
    }

    cout << "hon" << endl;
    return 0;
}