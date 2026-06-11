/*  Isn't it lovely, all alone?             */
/*  Heart made of glass, my mind of stone   */
/*  Tear me to pieces, skin to bone         */
/*  Hello, welcome home                     */

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

string s;
cin>>s;

if((s[2]==s[3]) && s[4]==s[5])
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;

}
return 0;
}











