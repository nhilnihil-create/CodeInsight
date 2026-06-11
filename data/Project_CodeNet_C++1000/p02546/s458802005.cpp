#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S[S.size() - 1] == 's') {
        cout << S + "es" << endl;
    }
    else {
        cout << S + "s" << endl;
    }
}