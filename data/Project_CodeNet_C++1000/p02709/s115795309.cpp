    #include <bits/stdc++.h>
     
        using namespace std;
        #define sd(x) scanf("%d",&x);
        #define sdl(x) scanf("%lld",&x);
        #define pr(x) printf("%d\n",x);
        #define prl(x) printf("%lld\n",x);
long long dp[2001][2001];

    bool comp(pair<int,int>a,pair<int,int>b)
    {
        return a.first>b.first;   
    }
    void solve()
    {
        int n;cin >> n;
        vector<pair<int,int>>arr;
        for (int c=0;c<n;c++)
            {int a;cin >> a;arr.push_back(make_pair(a,c));}
        sort(arr.begin(),arr.end(),comp);

        dp[0][0]=1LL*arr[0].first*(n-1-arr[0].second);
        dp[0][1]=1LL*arr[0].first*arr[0].second;
        for (int c=1;c<n;c++)
            for (int c1=0;c1<=c+1;c1++)
                {
                    
                    if (c1<=c)
                        dp[c][c1]=dp[c-1][c1]+1LL*arr[c].first*abs(n-1-(c-c1)-arr[c].second);
                    if (c1!=0)
                        dp[c][c1]=max(dp[c][c1],dp[c-1][c1-1]+1LL*arr[c].first*abs(arr[c].second-(c1-1)));

                }
        long long maxi=-1;
        for (int c=0;c<n;c++)
            maxi=max(maxi,dp[n-1][c]);
        
      
        cout << maxi << endl;
            
        
            
        
    }

    int main ()
    {
      
     int t;
     //cin >> t;
     t=1;

     for (int tt=1;tt<=t;tt++)
     {
         solve();
     }

    return 0;
     
     
     
     
        }
