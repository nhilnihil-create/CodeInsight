#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pi acos(-1.0)

int main()
{
    ll i, j, a, b, k, n, m, cnt = 0;
    cin >> a >> b >> k;
    if(k - a >= 0){
        k -= a;
        cout << 0 << " ";
        if(k - b >= 0)
        {
            cout << 0 << endl;
            return 0;
        }
        else
            cout << abs(k - b) << endl;
    }
    else
        cout << abs(k - a) << " " << b << endl;
        

    return 0;
}
