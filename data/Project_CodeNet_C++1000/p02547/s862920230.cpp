#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;
    while(n--) {
        int x, y;
        cin >> x >> y;
        if(x == y)
            c++;
        else
            c = 0;
        if(c == 3) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}