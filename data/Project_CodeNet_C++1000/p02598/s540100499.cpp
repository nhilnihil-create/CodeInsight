
// Problem: E - Logs
// Contest: AtCoder - AtCoder Beginner Contest 174
// URL: https://atcoder.jp/contests/abc174/tasks/abc174_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
    
    int main()
    {
        FAST
        int t;
        t = 1;

        while(t--)
        {
           int n , k;
           cin >> n >> k;
           
           vector<int> a(n);
           for(auto &x : a)
           {
               cin >> x;
           }
           
           int l = 0 , r = *max_element(a.begin() , a.end());
           
           while(l < r - 1)
           {
               int mid = (l + r) / 2 ;
               int c = 0;
               
               for(auto x : a)
               {
                   c += (x - 1) / mid;
               }
               
               if(c <= k)
               {
                   r = mid;
               }
               else l = mid;
           }
           
           cout << r << endl;
        }
    }

