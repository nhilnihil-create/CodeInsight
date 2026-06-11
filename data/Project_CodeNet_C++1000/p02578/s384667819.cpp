#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A1, A2;
    cin >> A1;
    long long sum = 0;
    for (int i = 1; i < N; i++) {
        cin >> A2;
        sum += max(0, A1 - A2);
        A1 = max(A1, A2);
    }
    cout << sum << endl;
}
