#include <bits/stdc++.h>
using namespace std;
#define round_up(a, b) (a + (b - 1)) / b

int main()
{
    int n;
    cin >> n;

    cout << round_up(n, 2) << endl;
    return 0;
}