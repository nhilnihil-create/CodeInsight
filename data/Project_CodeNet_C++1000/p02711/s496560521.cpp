#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_io;
    int n;
    cin >> n;
    int a,cnt=0;
    while( n != 0)
    {
        a = n % 10;
        n = n / 10;
        if(a == 7)
        {
            cnt++;
            break;
        }
    }
    if(cnt > 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
