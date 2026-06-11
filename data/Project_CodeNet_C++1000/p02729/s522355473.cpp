#include<iostream>
using namespace std;
int main (void)
{

    int n, m;

    cin >> n >> m;

    n = (n * (n - 1)) / 2;
    m = (m * (m - 1)) / 2;

    n += m;

    cout << n << endl;
    return 0;
}
