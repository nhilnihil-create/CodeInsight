#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
int main(){
        int a, b, c; cin >> a >> b >> c;
        if ((a == b && a != c) || (b == c && b != a) || (c == a && c != b)) cout << "Yes";
        else cout << "No";
    return 0;
}

