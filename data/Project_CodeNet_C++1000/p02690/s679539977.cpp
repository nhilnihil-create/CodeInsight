#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll X;
    cin >> X;
    for(int i = -2000; i <= 2000; i++){
        for(int j = -2000; j <= i; j++){
            ll x = (ll)i*i*i*i*i, y = (ll)j*j*j*j*j;
            if(x - y == X){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    return 0;
}