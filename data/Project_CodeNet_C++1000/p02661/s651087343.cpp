/*    Isn't it lovely, all alone?              */
/*    Heart made of glass, my mind of stone    */
/*    Tear me to pieces, skin to bone          */
/*    Hello, welcome home                      */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
ll mod=1000000007;

int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll t=1;
//cin>>t;
while(t--)
{


ll low,high;

ll n,i;
cin>>n;

ll a[n+1],b[n+1];

for(i=1;i<=n;i++)
cin>>a[i]>>b[i];

sort(a+1,a+n+1);
sort(b+1,b+n+1);


if(n%2==1)
{
  low=a[(n+1)/2];
  high=b[(n+1)/2];

 cout<<high-low+1<<endl;

}
else
{

ll h,l;

l=(a[n/2]+a[(n/2)+1]);
h=(b[n/2]+b[(n/2)+1]);

cout<<h-l+1<<endl;


}


}
return 0;
}





