#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<ll>>;

int main(void)
{
    ll k,a,b;
    cin >> k;
    cin >> a >> b;
    bool judge=false;
    for(int x=a/k;x*k<=b;x++)
    {
        if(x*k>=a && x*k<=b)
        {
            judge=true;
        }
    }
    if(judge)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "NG" << endl;
    }
    
    return 0;
}
