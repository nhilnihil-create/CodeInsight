#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    int n;
    cin >> n;
    bool found = false;
    while(n != 0)
    {
        if(n % 10 == 7)
        {
            found = true;
            break;
        }
        n /= 10;
    }
    if(found)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
