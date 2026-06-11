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
    int n;
    cin >> n;
    vector<ll> a, b;
    while( n-- ){
        ll x, y;
        cin >> x >> y;
        a.push_back(x+y);
        b.push_back(x-y);
    }
    cout << max(
                (*max_element( a.begin(), a.end() )) - (*min_element( a.begin(), a.end() )),
                (*max_element( b.begin(), b.end() )) - (*min_element( b.begin(), b.end() ))
                ) << '\n';
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
