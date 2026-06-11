#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X;
    cin >> X;
    long long amount = 100;
    long long year = 0;

    long long risi = 0;
    while (amount < X)
    {
        risi = amount / 100;
        amount += risi;
        year++;
    }

    cout << year << endl;
}