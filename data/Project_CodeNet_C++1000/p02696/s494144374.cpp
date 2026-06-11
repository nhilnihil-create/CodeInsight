#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    ll a, b, n, z, x, y;
    cin >> a >> b >> n;
    if(n < b){
        x = (a*n)/b;
        y = 0;
    }
    else{
        n = b-1;
        x = (a*n)/b;
        y = 0;
    }
    cout <<x-y;



}





///promy_pompom
//hello world
