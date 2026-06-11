#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x) {
    if (x == 2)
        return true;
    if (x < 2 || x % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int n, cnt;
    while (cin >> n, n) {
        cnt = 0;
        for (int i = n + 1; i <= n * 2; ++i) {
            if (isPrime(i))
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}