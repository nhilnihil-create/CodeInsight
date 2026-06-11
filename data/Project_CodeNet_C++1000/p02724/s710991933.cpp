#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    int n;
    cin >> n;
    ll yen500 = n / 500;
    n -= (yen500 * 500);
    ll yen5 = n / 5;
    ll happiness = (yen500 * 1000) + (yen5 * 5);
    cout << happiness << "\n";
}
