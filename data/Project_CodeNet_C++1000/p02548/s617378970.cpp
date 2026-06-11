#include<bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;

int main()
{
    int n, cnt=0,ans=0;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        if(n%i == 0)
            ans += (n/i) - 1;
        else
            ans += (n/i);
    }
    cout << ans;
    return 0;
}
