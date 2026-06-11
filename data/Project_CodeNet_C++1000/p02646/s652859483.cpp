#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;

    if (T * (V - W) >= abs(A - B))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
