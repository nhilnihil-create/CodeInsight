    #include <bits/stdc++.h>
     using namespace  std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    // What follows is a magical ordered_set data structure.
    // Supports the following functions:
    // find_by_order(ll k) - returns k'th smallest element (0-indexed)
    // order_of_key(ll k) - returns number of elements strictly smaller than k.
    using namespace __gnu_pbds;
    #define ordered_set tree <ll, null_type, less_equal <ll>, rb_tree_tag, tree_order_statistics_node_update> 
     
    #define mp make_pair
    #define pb push_back
    #define ff first
    #define ss second
    // #define ll long long
    const double pi=3.1415926535897932384626433832;
     long long mod= 1e9+7;
    //long long primeset[5000000]={};
    typedef complex<double> cd;
    typedef long long ll;
    typedef double ld;
    //#define For(i,0,n) for(long long i = 0 ; i<n ;i++) 
    //cd god (mod,0);
     
    cd fast_exp(cd a, long long b)
    {
    	if (b == 0)
    		return 1;
    	
    	cd res = fast_exp(a, b / 2);
    		
    	res = res *res;
    	
    	if (b % 2 == 1)
    		{
    			res = res * a;
    		 
     
    		}    
    	
    	return res;
    }
     
    long long fastexpon(long long a,long long b,long long mod)
    {
    	if(b==0)
    		return 1LL;
    	
    	long long res=fastexpon(a,b/2,mod);
    	
    	res=(res*res)%mod;
    	if(b%2==1)
    		res= (res * a)%mod;
     
    	return res;
    }
     
     
    //TEMPLATE ENDS HERE!!!! ------------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------------
     
     
struct custom
{
    bool operator()(ll a, ll b)
    {
		return a > b;
    }
};


double findangle(double x, double y)
{
    if(x>=0 && y>=0)
    {
        if(x!=0)
        return atan(y/x);

        else
        return pi/2;
    }

    else if(x<0 && y>=0)
    {
        x = abs(x);
        y = abs(y);
        return pi - atan(y/x);
    }
    else if(x<=0 && y<0)
    {
        x = abs(x);
        y = abs(y);
        if(x==0)
            return 3*pi/2;
        else
            return pi + atan(y/x);
    }
    else
    {
        x = abs(x);
        y = abs(y);
        
        return 2*pi - atan(y/x);
        
    }    
}


int main()
{
     
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
        cout.precision(30);
        vector<pair<ll,ll>> v;
        ll x,y;
        int n;
        cin>>n;

        for(int i = 0; i<n ;i++)
        {
            cin>>x>>y;
            v.pb(mp(x,y));
        }

        sort(v.begin(),v.end(),[](pair<ll,ll> a , pair<ll,ll> b){ return atan2(a.ff,a.ss) < atan2(b.ff,b.ss);} );

        ll cumulx[n+1]={} , cumuly[n+1]={};
        
        for(int i = 1 ; i<=n ;i++)
        {
            cumulx[i]=v[i-1].ff + cumulx[i-1];
            cumuly[i]=v[i-1].ss + cumuly[i-1];
        }

        double truans = 0;

        // for(int i = 0 ; i<n ; i++)
        // {
        //     for(int j = i+1 ; j<=n ;j++)
        //     {
        //         ll delx = cumulx[j] - cumulx[i];
        //         ll dely = cumuly[j] - cumuly[i];

        //         double cur  = sqrt(delx*delx + dely*dely);
        //         if(cur>truans)
        //             truans = cur;
        //     }
        // }
    double res = 0, store;
    for(ll len=1;len<=n;len++)
    {
        for(ll j=0;j<n;j++)
        {
            ll xsum=0;
            ll ysum=0;
            ll curridx=j;
            for(ll k=0;k<len;k++)
            {
                xsum+=v[curridx].first;
                ysum+=v[curridx].second;
                curridx=(curridx+1);
                if(curridx>=n)
                {
                    curridx-=n;
                }
            }
            store=double(xsum*xsum);
            store+=(double)(ysum*ysum);
            store=sqrt(store);
            if(res<=store)
            {
                res=store;
            }
        }
    }

        cout << fixed << setprecision(20) << res << endl;


        return 0;
     
}