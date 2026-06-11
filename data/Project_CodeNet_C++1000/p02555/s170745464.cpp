



    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define FAST ios_base::sync_with_stdio(false);cin.tie(0);
    const double EPS = 1e-9;
    const double PI = acos(-1);
    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
    //const int dx[]={0,0,0,1,1,1,-1,-1,-1};
    //const int dy[]={-1,0,1,-1,0,1,-1,0,1};
    const int dx[] = {0 , 1 , 0 , -1};
    const int dy[] = {1 , 0 , -1 , 0};
    //#define MOD         1000000007LL
    #define MAX         1000005
    const ll MOD = 1000000000 + 7;
    
    int main()
    {
        FAST
        int t;
        t = 1;

        while(t--)
        {
           int n;
           cin >> n;
           
           vector<int> dp(n + 5);
           
           for(int i = 3 ; i <= n ; i++)dp[i] = 1;
           
           for(int i = 3 ; i <= n ; i++)
           {
               for(int j = 3 ; j <= n ; j++)
               {
                   if(i - j < 3)break;
                   
                   dp[i] += dp[i - j];
                   dp[i] %= MOD;
               }
           }
           
           cout << dp[n] << endl;
        }
    }

