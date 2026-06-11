#include <algorithm>
#include <iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;
    if(x<0)
        x = -x;

    ll t = x / d;


    if(t>=k){
        cout << x - k * d;

    }else{
        x %= d;
        k -= t;
        bool a = x > d / 2;
        bool b = k % 2;
        if(a==b)
            cout << min(x, d - x);
        else {
            if(a && !b)
                cout << x;
            if(!a && b)
                cout << d - x;
        }

    }

    return 0;
}
