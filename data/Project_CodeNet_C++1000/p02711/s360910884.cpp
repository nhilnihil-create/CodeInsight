#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string n;
    cin >> n;
    for (int i = 0; i < n.size(); ++i) {
        if(n[i] == '7') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

}