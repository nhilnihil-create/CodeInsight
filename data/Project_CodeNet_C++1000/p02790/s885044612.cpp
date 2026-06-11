#include<iostream>
#include<string>
using namespace std;

int main() {
    string res = "";
    int a, b;
    cin >> a >> b;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = 0; i < b; i++) {
        res += (a + '0');
    }
    cout << res << endl;
    return 0;
}
