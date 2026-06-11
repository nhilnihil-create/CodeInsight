#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x;
ll ans = 0;
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;

    while (x >= 500){
        x -= 500;
        ans += 1000; 
    }
 
    while (x >= 5){
        x -= 5;
        ans+= 5;
    }

    cout << ans << endl;
    return 0;
}