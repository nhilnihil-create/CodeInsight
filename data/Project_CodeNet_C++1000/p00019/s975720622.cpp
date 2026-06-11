#include <iostream>

using namespace std;

long long fact(int n) {
    return (n == 1) ? 1 : n * fact(n - 1);
}

int main()
{
    int n;
    
    while (cin >> n) {
        cout << fact(n) << endl;
    }

    return 0;
}