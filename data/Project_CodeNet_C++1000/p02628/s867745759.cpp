#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    int min_price = 0;

    cin >> n >> k;

    vector<int> p(n);

    for (int i = 0; i < n ; i++)
    {
        cin >> p.at(i);
    }
    sort(p.begin(), p.end());

    for (int i = 0 ; i < k ; i++)
    {
        min_price += p.at(i);
    }

    cout << min_price << endl;
    return 0;
}