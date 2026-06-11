#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <set>

using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define ll  long long




void solve()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll c1, c2, c3, c4;
    c1 = a * c;
    c2 = a * d;
    c3 = b * c;
    c4 = b * d;
    if (c1 >= c2 && c1 >= c3 && c1 >= c4)
        cout << c1 << '\n';
    
    else if (c2 >= c1 && c2 >= c3 && c2 >= c4)
        cout << c2 << '\n';
    
    else if (c3 >= c1 && c3 >= c2 && c3 >= c4)
        cout << c3 << '\n';
    
    else if (c4 >= c1 && c4 >= c2 && c4 >= c3)
        cout << c4 << '\n';
    
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
}
