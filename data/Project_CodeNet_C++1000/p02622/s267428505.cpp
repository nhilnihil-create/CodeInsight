#include<iostream>
using namespace std;

string S, T;

void read() {
    cin >> S >> T;
}


void work() {
    int cnt = 0;
    for (int i = 0; i < S.size(); ++i) {
        cnt += S[i] != T[i];
    }
    cout << cnt << endl;
}


int main() {
    read();
    work();
    return 0;
}
