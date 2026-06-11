#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    ll s,w;
    cin >> s >> w;
    if(w>=s)
    {
        cout << "unsafe" << endl;
    }
    else
    {
        cout << "safe" << endl;
    }
    
    return 0;
}
