#include<iostream>

using namespace std;
int main() {
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)break;
        int o = a + b;
        if (a == -1 || b == -1)cout << "F" << endl;
        else if (o >= 80)cout << "A" << endl;
        else if (o >= 65 && o < 80)cout << "B" << endl;
        else if (o >= 50 && o < 65)cout << "C" << endl;
        else if (o >= 30 && o < 50 && c >= 50)cout << "C" << endl;
        else if (o < 30)cout << "F" << endl;
        else cout << "D" << endl;
    }
    return 0;
}