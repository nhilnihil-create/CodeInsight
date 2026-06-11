#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    ll n, i, j, c, a, m = 0;
    cin >> n;
    for(i = 1; i <= sqrt(n) + 1; i++){
        if(n % i == 0){
            a = n / i;
            m = max(m, i);
        }
    }
    c = (m - 1) + ((n / m) - 1);
    cout << c;


}





///promy_pompom
//hello world