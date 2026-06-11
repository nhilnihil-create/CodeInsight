#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res = 0;
    string n;
    cin >> n;

    for(int i = 0; i < n.size(); ++i)
    {
        res += n[i] - '0';
    }

    cout << (res % 9 == 0 ? "Yes" : "No") << "\n";  
    return 0;
}
