#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    if(y > 4 * x || y < 2 * x) {
        cout << "No" << "\n";
        return 0;
    }
    if(y % 2 != 0){
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    return 0;
}
