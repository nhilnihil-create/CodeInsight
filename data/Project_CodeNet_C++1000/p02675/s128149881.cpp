#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void)
{
    ll n;
    cin >> n;
    n%=10;
    //cout << n << endl;
    if(n== 0 || n== 1 || n== 6 || n== 8)
    {
        cout << "pon" << endl;
    }
    else if(n== 3)
    {
        cout << "bon" << endl;
    }
    else
    {
        cout << "hon" << endl;
    }
    
    return 0;
}
