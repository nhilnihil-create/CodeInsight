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
        t = 1;;

        while(t--)
        {
           int h , w , f;
           cin >> h >> w >> f;

          
           char maze[h + 1][w + 1];

           for(int i = 0 ; i < h ; i++)
           {
               cin >> maze[i];
           }
         

           int ans = 0;

           for(int i = 0 ; i < (1 << h) ; i++)
           {
              for(int j = 0 ; j < (1 << w) ; j++)
              {
                  int total = 0;
                  
                  for(int k = 0 ; k < h ; k++)
                  {
                      for(int l = 0 ; l < w ; l++)
                      {
                          if((i & (1 << k)) && (j & (1 << l)) && maze[k][l] == '#')
                          {
                              total++;
                          }
                      }
                  }
                  if(total == f)ans++;
              }    
           }

           cout << ans << endl;
        }
    }

