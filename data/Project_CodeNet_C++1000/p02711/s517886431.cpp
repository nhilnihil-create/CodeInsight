#include <bits/stdc++.h>
#define ll long long
#define L long
#define endl "\n"
#define _START_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _END_ return 0;
using namespace std;

int main()
{   
    _START_

    int n;
    cin >> n;
    while (n != 0)
    {
        if (n % 10 == 7)
        {
            cout<< "Yes";
            return 0;
        }
        n /= 10;
    }
    cout<< "No";

    _END_
}