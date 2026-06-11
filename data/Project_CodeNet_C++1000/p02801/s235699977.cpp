#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string alp ="abcdefghijklmnopqrstuvwxyz";
    char c[2];
    cin >> c;
    for (int i = 0; alp.size(); i++) {
        if (alp[i] == *c) {
            cout << alp[i+1] << endl;
            return 0;
        }
    }

    return 0;
}