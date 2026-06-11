#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string cad;
    cin >> cad;

    if(cad.back() == 's')cad += "es";
    else cad += "s";

    cout << cad << '\n';

    return 0;
}