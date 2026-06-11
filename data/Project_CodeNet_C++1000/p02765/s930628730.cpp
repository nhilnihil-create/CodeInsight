#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll N, R;
    cin >> N >> R;
    
    if (N <= 10) {
        cout << R + (100 * (10 - N));
    } else {
        cout << R << endl;
    }
}