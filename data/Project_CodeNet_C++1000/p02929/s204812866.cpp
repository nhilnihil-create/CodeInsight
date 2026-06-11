#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define vll vector<lli>
#define stp setprecision(15)
#define eps 0.000001
#define endl '\n'
#define ll lli
 
using namespace std ;
 
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define N 200010
#define lg 19



int main() 
{ 

/////////////////////////////////////
    
    fastio;
 
/////////////////////////////////////    

    lli n;
    cin>>n;

    string s;
    cin>>s;
    if(s[0] == 'W') 
    {
        cout<<0;
        return 0;
    }

    lli o = 1,ans=1;

    loopl(i,1,2*n)
    {
        if(s[i] == 'B')
        {
            if(o%2)
            {
                ans = (ans*o)%mod;
                o--;
            }

            else
                o++;
        }

        else
        {
            if(o%2)
                o++;

            else
            {
                ans = (ans*o)%mod ;
                o--;
            }
        }
    }
    if(o)
        cout<<0;

    else
    {
        loopl(i,1,n+1)
        {
            ans = (ans*i)%mod;
        }
        cout<<ans;
    }


}   


