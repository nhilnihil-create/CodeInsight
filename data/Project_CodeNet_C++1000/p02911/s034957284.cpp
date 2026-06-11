#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, q, a[100000];

int main()
{
    cin >> n >> k >> q;
    for (int i = 0; i < q; i++)
    {
        int x; cin >> x;
        a[--x]++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ((k - q + a[i] > 0)? "Yes\n":"No\n");
    }
}