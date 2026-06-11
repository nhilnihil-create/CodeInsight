 #include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = 0; i < b; i++) {
        cout << (char)('0' + a);
    }
    cout << endl;
    return 0;
}
