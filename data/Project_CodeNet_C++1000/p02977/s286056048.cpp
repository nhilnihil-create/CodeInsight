#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(int n) {
    while (n > 1) {
        if (n%2 == 1) {
            return false;
        }
        n /= 2;
    }
    return true;
}

long long keta(int n) {
    int ret = 0;
    while (n > 1) {
        n /= 2;
        ret++;
    }
    return ret;
}

int main() {
    long long n = 0;
    cin >> n;
    if (n == 1) cout << "No" << endl;
    else if (check(n)) cout << "No" << endl;
    else if ((n+1)%2 == 0) {
        if ((n+1)%4 == 0) {
            cout << "Yes" << endl;
            long long a = 1, b = 2;
            while (b <= n*2) {
                cout << a << " " << b << endl;
                a++;
                b++;
            }
        }
        else {
            cout << "Yes" << endl;
            long long a = 1, b = 2;
            while (b <= n-2) {
                cout << a << " " << b << endl;
                cout << a+n << " " << b+n << endl;
                a++;
                b++;
            }
            cout << n-2 << " " << n+1 << endl;
            cout << n-1 << " " << n << endl;
            cout << n << " " << 2 << endl;
            cout << 3 << " " << 2*n-1 << endl;
            cout << 2*n-1 << " " << 2*n << endl;
        }
    }
    else {
        if (n%4 == 0) {
            cout << "Yes" << endl;
            long long a = 1, b = 2;
            while (b <= n-5) {
                cout << a << " " << b << endl;
                cout << a+n << " " << b+n << endl;
                a++;
                b++;
            }
            long long buf = pow(2, keta(n));
            cout << n-5 << " " << n+1 << endl;
            cout << n-1 << " " << n-2 << endl;
            cout << n-1 << " " << n-buf << endl;
            cout << n-buf+1 << " " << 2*n-2 << endl;
            cout << 2*n-2 << " " << 2*n-1 << endl;
            cout << n-3 << " " << n-4 << endl;
            cout << n-3 << " " << n-buf-2 << endl;
            cout << n-buf-1 << " " << 2*n-4 << endl;
            cout << 2*n-4 << " " << 2*n-3 << endl;
            cout << n << " " << n-1 << endl;
            cout << 2*n << " " << n-buf-1 << endl;
        }
        else {
            cout << "Yes" << endl;
            long long a = 1, b = 2;
            while (b <= n-3) {
                cout << a << " " << b << endl;
                cout << a+n << " " << b+n << endl;
                a++;
                b++;
            }
            long long buf = pow(2, keta(n));
            cout << n-3 << " " << n+1 << endl;
            cout << n-1 << " " << n-2 << endl;
            cout << n-1 << " " << n-buf << endl;
            cout << n-buf+1 << " " << 2*n-2 << endl;
            cout << 2*n-2 << " " << 2*n-1 << endl;
            cout << n << " " << n-1 << endl;
            cout << 2*n << " " << n-buf-1 << endl;
        }
    }
    return 0;
}
