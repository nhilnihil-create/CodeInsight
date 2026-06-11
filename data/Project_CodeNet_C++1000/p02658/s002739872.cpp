#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    unsigned long long result = 1, border = 1000000000000000000;

    cin >> n;

    vector<unsigned long long> a(n);

    for (int i = 0; i < n ; i++)
    {
        cin >> a.at(i);
        if(0 == a.at(i))
        {
            cout << 0 << endl;
            return 0; 
        }
    }
    sort(a.begin(),a.end());

    for (int i = 0; i < n ; i++)
    {
        result *= a.at(i);
        border /= a.at(i);

        if(border <= 0 )
        {
            cout << -1 << endl;
            return 0;        
        }
    }

    cout << result << endl;
    return 0;
}