#include<iostream>
using namespace std;

int main() {
    string S; cin >> S;
    if (S[S.size() - 1] == 's') {
        S += "es";
    } else {
        S += 's';
    }
    cout << S << endl;
}
