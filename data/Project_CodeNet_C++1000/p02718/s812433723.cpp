#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll m,n,i,total=0,cnt=0;
    cin >> n >> m;

    ll a[n];

    for(i=0; i<n; i++){
       cin >> a[i];
       total += a[i];
    }

    for(i=0; i<n; i++){
        if(a[i] * 4 * m >= total )
        cnt++;
    }

    if(cnt >= m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;

}