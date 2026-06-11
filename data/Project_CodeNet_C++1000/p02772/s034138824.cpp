#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int a;
    rep(i, n) {
        cin >> a;
        if (a%2 == 1) continue;
        if (!(a % 2 == 0 && (a%3 == 0 || a%5 == 0))) {
            cout << "DENIED" << endl;
            return 0;
        }
    }

    cout << "APPROVED" << endl;
 
    return 0;
}