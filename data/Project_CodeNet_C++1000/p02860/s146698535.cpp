#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    string s, t1, t2; cin >> s;
    if(n % 2 == 0) {
        t1 = s.substr(0, n/2);
        t2 = s.substr(n/2, n/2);
        if(t1 == t2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
