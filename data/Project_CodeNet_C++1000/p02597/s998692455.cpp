#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string c;
    cin >> c;
    int cR = count(c.begin(), c.end(), 'R');
    cout << count(c.begin(), c.begin()+cR, 'W') << endl;
    return 0;
}