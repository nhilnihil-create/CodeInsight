#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k;
ll ans;
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    if (n % k <= k/2){
        cout << n % k << endl;
    }
    else{
        cout << k - (n % k) << endl;
    }
 
    return 0;
}
