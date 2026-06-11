#include <iostream>

using namespace std;

int main()
{
    long n;
    long long d{-1};
    long long c{-1};
    cin >> n;
    for (long i = 0; i < n; i++)
    {
        long long first, second;
        cin >> first >> second;
        c += first * second;
        d += second;
    }
    cout << c / 9 + d << '\n';
    return 0;
}
