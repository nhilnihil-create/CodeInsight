#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int X, Y;

int main() {
    cin >> X >> Y;

    if (Y % 2 == 0) {
        if (Y/2 - X >= 0 && 2*X - Y/2 >= 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
    
    return 0;
}
