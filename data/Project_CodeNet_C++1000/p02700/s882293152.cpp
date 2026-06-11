#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    while(a>0 && c>0)
    {
        c-=b;
        a-=d;
    } 
    if(c<=0)
    {
        cout << "Yes" << endl; 
    }
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}
