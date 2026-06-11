#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    auto sum = 0L;
    for (auto i = 1; i <= n; i++)
        if (i % 3 != 0 && i % 5 != 0) sum += i;

    cout << sum;
}