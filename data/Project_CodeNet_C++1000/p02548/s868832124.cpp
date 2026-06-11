#include <iostream>
#include <cstdio>
using namespace std;
int n,ans;
signed main()
{
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
                // for (int j=1; j<=n; j++) {
                //         if (i*j<n) ans++;
                //         else break;
                // }
                ans+=n/i;
                if (n%i==0) ans--;
        }
        cout<<ans<<"\n";
        return 0;
}
