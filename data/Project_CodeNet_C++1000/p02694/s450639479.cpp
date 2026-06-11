#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    ll start = 100, x, cntr = 1;
    cin >> x;
    while(true){
        start += ((start * 1)/(100));
        if(start >= x)
            return cout << cntr, 0;
        cntr++;
    }
    return 0;
}