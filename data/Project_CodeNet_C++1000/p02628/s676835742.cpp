#include <bits/stdc++.h>

using namespace std;

void fast();

/*
*
* Watch out! Another Buggy Code From Muhammad_Mamdouh, Happy Coding;
*
*/

int main()
{
    fast();
    int n, k, price[1005] = { 0 };

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> price[i];

    sort(price, price + n);

    int mn_price = 0;
    for (int i = 0; i < k; ++i)
        mn_price += price[i];

    cout << mn_price;

    return 0;
}

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}