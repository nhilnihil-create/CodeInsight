#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int> price;
    int n, k, result = 0;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        int p;
        cin >> p;
        price.insert(p);
    }
    for(auto i : price)
    {
        if(k==0)
            break;
        result += i;
        k--;
    }
    cout << result;
    return 0;
}