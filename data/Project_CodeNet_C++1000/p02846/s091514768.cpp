 #pragma comment(linker, "/stack:200000000")
 #pragma GCC optimize("Ofast")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
//  #ifndef ONLINE_JUDGE
//     freopen ("INPUT.txt" , "r" , stdin);
//     freopen ("OUTPUT.txt" , "w" , stdout);
//  #endif
    

// -------------------------------------Code starts here--------------------------------------------------------------------- 

    int t1,t2;
    cin>>t1>>t2;
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int x=a1*t1+a2*t2;
    int y=b1*t1+b2*t2;
    if(x==y)
    {
        cout<<"infinity";
        return 0;
    }

    if(x<y)
    {
        if(a1<b1)
        {
            cout<<0;
            return 0;
        }
        else
        {
            int z=(a1-b1)*t1;
            int dis=y-x;
            int ans=z/dis;
            ans*=2;
            if(z%dis==0)
            {
                ans--;
            }
            
            cout<<ans+1;
        }
    }
    else
    {
        if(b1<a1)
        {
            cout<<0;
            return 0;
        }
        else
        {
            int z=(b1-a1)*t1;
            int dis=x-y;
            int ans=z/dis;
            ans*=2;
            if(z%dis==0)
            {
                ans--;
            }
            cout<<ans+1;
        }
    }
    

// -------------------------------------Code ends here------------------------------------------------------
     clock_t clk;
 	clk = clock();
 
     clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }