//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,i,j,plugs = 1,ans = 0;
    cin >> a >> b;
    while(plugs < b)
    {
        plugs--;
        plugs += a;
        ans++;
    }
    cout << ans << endl;


    return 0;
}



