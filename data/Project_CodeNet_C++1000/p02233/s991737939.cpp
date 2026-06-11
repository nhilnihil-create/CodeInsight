#include <iostream>
using namespace std;

int n;
int F[45];
int fibo(int i) {
    if (F[i]) {
        return F[i];
    }
    F[i] =  fibo(i - 1) + fibo(i-2);
    return F[i];
}

int main() {
    cin >> n;
    F[0] = F[1] = 1;
    cout << fibo(n) << endl;

    return 0;
}

