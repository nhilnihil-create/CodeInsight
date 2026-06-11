#include <iostream>
#define ll long long
#define the_flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int main() 
{
    the_flash;
    ll a, b;
    cin >> a >> b;
    ll res = (a + b) / 2;

    if ((a - b) % 2 == 0)
        cout << res << "\n";
    
    else 
        cout << "IMPOSSIBLE" << "\n";
    return 0;
}