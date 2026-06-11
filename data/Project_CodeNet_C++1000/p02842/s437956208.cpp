#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    for(i = 0;i < 1e5;++i){
        if(i*108/100 == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}