#include <bits/stdc++.h>
using namespace std;

// 
int main() {
    long long A, B;
    cin >> A >> B;
    long long minNum = min(A, B);
    long long i = 1;
    while ((minNum * i) % A != 0 || (minNum * i) % B != 0) {
        i++;
    }
    cout << minNum * i;
}
