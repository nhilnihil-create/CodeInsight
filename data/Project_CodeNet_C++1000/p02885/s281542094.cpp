#include<bits/stdc++.h>
using namespace std;

#define ll long long
//#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
  //  fast_io;
    int a,b;
    cin >> a >> b;
    b = 2 * b;
    int ans = a - b;
    if(ans < 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << ans << "\n";
    }

}
