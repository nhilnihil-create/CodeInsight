#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> a(n);

    bool res = true;

    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if(tmp % 2 == 0)
        {
            if(tmp % 3 && tmp % 5)
                res = false;
        }
    }

    cout << (res ? "APPROVED" : "DENIED") << "\n";
    return 0;
}