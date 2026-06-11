#include <iostream>

using namespace std;
#define ll long long

int main() {
    ll N;
    cin >> N;
    N--;
    cout << N * (N + 1) / 2 << endl;
    return 0;
}