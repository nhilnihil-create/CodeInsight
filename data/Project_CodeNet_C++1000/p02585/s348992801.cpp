
// Problem: D - Moving Piece
// Contest: AtCoder - AtCoder Beginner Contest 175
// URL: https://atcoder.jp/contests/abc175/tasks/abc175_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)



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
    int p[5010],c[5010];
    int vis[5010];
    pair<int, long long int> period[5010];
    int main()
    {
        FAST
        int t;
        t = 1;

        while(t--)
        {
           int n , k;
           cin >> n >> k;
           
           for(int i = 1 ; i <= n ; i++)
           {
               cin >> p[i];
           }
           
           for(int i = 1 ; i <= n ; i++)cin >> c[i];
           
           for(int i = 1 ; i <= n ; i++)
           {
               int m = i;
               ll s = 0;
               for(int i = 1 ; i <= n ; i++)vis[i] = 0;
               
               for(int j = 0 ; j <= n ; j++)
               {
                   if(vis[m])
                   {
                       period[i] = make_pair(j , s);
                       break;
                   }
                   vis[m] = 1;
                   m = p[m];
                   s += c[m];
               }
           }
           
           ll ans = LLONG_MIN;
           
           for(int i = 1 ; i <= n ; i++)
           {
               int m = i;
               ll s = 0;
               for(int j = 1 ; j <= period[i].first ; j++)
               {
                   if(j > k)break;
                   m = p[m];
                   s += c[m];
                   int t = (k - j) / period[i].first;
                   ll s2 = s + t * period[i].second;
                   ans = max(ans , s);
                   ans = max(ans , s2);
               }
           }
           
           cout << ans << endl;
        }
    }

