#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main()
{
    ll x;
    cin >> x;
    for (ll i = -1000; i <= 1000; i++) {
        for (ll j = -1000; j <= 1000; j++) {
            if (i * i * i * i * i - j * j * j * j * j == x) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }

    return 0;
}