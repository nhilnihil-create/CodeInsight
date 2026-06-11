#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = 10; i < 1010; i++) {
        if (8*i/100 == a && i/10 == b) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;

    return 0;
}