#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int cost = 1000;
    while (cost < N) cost += 1000;
    cout << cost - N << endl;
}