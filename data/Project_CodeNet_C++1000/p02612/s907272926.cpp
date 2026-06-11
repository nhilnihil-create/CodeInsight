#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, coin_change, sheet_numbers;

    cin >> n;

    sheet_numbers = (n + 999) / 1000;
    coin_change = sheet_numbers*1000 - n;
    
    cout << coin_change << endl;
    return 0;
}