//-------All power is within you,you can do Anything and Everything.---------//
 
    #include <bits/stdc++.h>
    using namespace std;
  
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ M $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
 
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define sc(x) scanf("%lld",&x)
    #define pf(x) printf("%lld\n",x)
    #define int long long
    #define all(x) x.begin(),x.end() 
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x );
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    #define XOX 
    
    typedef vector<int> vi;
    typedef pair<int,int> pi; 
    
    const int MOD =  1000000007 ;
    const int MAX = 2e6 + 7;
    const int INF = 1e15;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ DEB $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define deb(x) cout<<#x<<" "<<x<<endl;

//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ V $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//  
    
    int i,j,k,t,n,q,l,r,mid;

//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ F $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    int x,ii,nn;
    set<int> st;

    void solve()
    {
        cin>>n;
        nn=sqrt(n);
        fo(i,2,nn+1)
        {
            if(n%i==0)
            {
                x=n;
                while(x>0 && x%i==0)x/=i;
                if(x%i==1)
                    st.insert(i);

                x=n;
                ii=n/i;
                while(x>0 && x%(ii)==0)x/=ii;
                if(x%ii==1)
                    st.insert(ii);
            }
        }

        n=n-1;
        nn=sqrt(n);

        fo(i,2,nn+1)
        {
            if(n%i==0)
            {
                st.insert(i);
                st.insert(n/i);
            }
        }
        if(n>1)
        st.insert(n);
        if(n+1>1)
        st.insert(n+1);

        cout<<st.size()<<endl;
        // for(auto x:st)deb(x)
        
    }
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
//                          GAME STARTS FROM HERE                            //
 
    int32_t main() 
    {
    
        // int start,stop=clock();
        // cout<<"time:"<<(stop-start)/double(CLOCKS_PER_SEC)*1000<<endl;
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        // sc(t);while(t--)
        // cin>>t;while(t--)
            solve();
    
        return 0;
    }