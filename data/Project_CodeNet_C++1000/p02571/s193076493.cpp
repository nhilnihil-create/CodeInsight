#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main()
{
    string a, b;
    cin >> a >> b;
    
    ll res = 1e12;
    for (int i = 0; i < a.length() - b.length() + 1; i++) {
        ll tmp = 0;
        for (int j = 0; j < b.length(); j++) {
            if (a[j + i] != b[j]) {
                tmp++;
            }
        }
        res = min(res, tmp);
    }
    cout << res;

    return 0;
}
