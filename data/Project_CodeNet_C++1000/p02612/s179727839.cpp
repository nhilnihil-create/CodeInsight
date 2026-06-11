#include<iostream>
using namespace std;

int main(void) {
    int N; cin >> N;
    if (N % 1000 == 0) {
        cout << 0 << endl;
    } else {
        cout << 1000 - N % 1000 << endl;
    }
}
