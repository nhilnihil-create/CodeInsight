#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    if (S[2] == S[3] && S[4] == S[5]) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

}