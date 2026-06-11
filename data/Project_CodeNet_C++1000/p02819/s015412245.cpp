#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define PMAX 200000


int main()
{
    int x;
    cin >> x;
    bool okflag;
    for (int i = x; i < PMAX; i++) {
        okflag = true;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) okflag = false;
        }
        if (okflag) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}