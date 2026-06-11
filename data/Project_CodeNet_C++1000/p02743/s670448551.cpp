#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll left = 4 * a * b;
    ll right = (c - a - b) * (c - a - b);

    if( (c - a - b) <= 0){
        cout << "No" << endl;
        return 0;
    }

    if(left < right){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
