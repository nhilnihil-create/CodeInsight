#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> h;

int fib(int n);

int fib(int n) {
    if (h.count(n) != 0) {
        return h[n];
    }

    int ret;
    if (n == 0) {
        ret = 1;
    }
    else if (n == 1) {
        ret = 1;
    }
    else {
        ret = fib(n-1) + fib(n-2);
    }
    h[n] = ret;
    return ret;
}

int main () {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}