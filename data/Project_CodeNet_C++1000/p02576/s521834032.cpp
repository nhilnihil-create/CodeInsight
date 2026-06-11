#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int X,N,T;
    cin >> N >> X>> T;
    int a, b;
    a = N / X;
    b = N % X;
    if (b != 0) {
        cout << T*(a + 1);
    }
    else {
        cout << T * a;
    }
}