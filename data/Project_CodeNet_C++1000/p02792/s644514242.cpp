#include<bits/stdc++.h>
using namespace std;

#define ll long long 
 
int main()
{
    ll t, i, j, k, ans, n, m, sum = 0, x;
 
    t = 1;
    while (t--)
    {
        cin>>n;
        ll cnt[10][10] = {0};
 
        for ( ll p = 1 ; p < n +1 ; p++)
		{
            ll l = p%10;
 
            k = p;
            while(k/10)k/=10;
            ll f = k;
            cnt[f][l]++;
        }
        ans=0;
        for (ll p = 1; p < 10 ; p++)
		{
			for ( ll q = 0 ; q < 10 ; q++)
            {
                ans += (cnt[p][q] * cnt[q][p]);
            }
        }
 
        cout<<ans;
    }
 
    return 0;
}