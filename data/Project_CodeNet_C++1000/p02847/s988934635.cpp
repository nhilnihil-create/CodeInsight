#include <bits/stdc++.h>
using namespace std;
typedef long long ll   ;  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s ;
    cin >> s ;
    if (s=="SUN")
        cout << 7 ;
    else if (s=="MON")
    {
        cout << 6 ;
    }
    else if (s=="TUE")
    {
        cout << 5 ;
    }
    else if (s=="WED")
    {
        cout << 4 ;
    }
    else if (s=="THU")
    {
        cout << 3 ;
    }
    else if (s=="FRI")
    {
        cout << 2 ;
    }
    else if (s=="SAT")
    {
        cout << 1 ;
    }
    

    return 0;
}