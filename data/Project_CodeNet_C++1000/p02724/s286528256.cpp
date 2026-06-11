#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    int n;

    cin >> n;

    int hund = n / 500;

    int five = (n - hund * 500) / 5;

    cout << (ll)(hund * 1000 + five * 5);

    return 0;
}
