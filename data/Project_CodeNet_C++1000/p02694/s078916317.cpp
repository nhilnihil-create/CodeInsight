// In the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n ;
    cin >> n ;
    ll val = 100, cnt = 0 ;
    while( val < n )
    {
        val += val/100 ;
        cnt++;
    }
    cout << cnt << endl;
}
