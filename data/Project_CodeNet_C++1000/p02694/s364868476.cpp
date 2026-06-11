#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll x; cin >> x;
    ll amt = 100L;
    int y = 0;
    while(amt < x){
        ++y;
        amt += (amt/100L);
    }
    cout << y << '\n';
    return 0;
}