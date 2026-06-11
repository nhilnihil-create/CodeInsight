#include <iostream>

using namespace std;

int main() {
    int N;
    string S;
    string T;
    cin >> N >> S;
    T = S.substr(N / 2);
    if (T + T == S) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}