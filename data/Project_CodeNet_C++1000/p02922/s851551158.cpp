#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int res = 0, outlet = 1;
    while (outlet < b)
    {
        outlet--;
        outlet += a;
        res++;
    }
    cout << res << endl;

    return 0;
}
