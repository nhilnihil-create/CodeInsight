#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << ((n&1)? (double(n / 2 + 1) / n):0.5) << "\n";
}