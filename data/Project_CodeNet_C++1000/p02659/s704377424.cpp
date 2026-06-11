#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int mod = 1e9+7;

int main()
{
    int64_t a;
    string b;

    cin >> a >> b;
    a = a * ((b[0]-'0') * 100 + (b[2]-'0') * 10 + (b[3]-'0'));
    a /= 100; 
    cout << a << endl;
}