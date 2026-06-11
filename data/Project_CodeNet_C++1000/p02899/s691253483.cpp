#include <iostream>

using namespace std;
int n,a,ans[1000000],i;
int main()
{
   cin >> n;
   for (i=1; i<=n; i++)
   {
       cin >> a;
       ans[a]=i;
   }
   for (i=1; i<=n; i++)
   cout<<ans[i]<<" ";

    return 0;
}
