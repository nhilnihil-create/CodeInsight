
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

           int row[h + 1] = { 0 }, col[w + 1] = { 0 };
           char maze[h + 1][w + 1];

           for(int i = 1 ; i <= h ; i++)
           {
               cin >> maze[i] + 1;
           }
           int total = 0;

           for(int i = 1 ; i <= h ; i++)
           {
               for(int j = 1 ; j <= w ; j++)
               {
                   if(maze[i][j] == '#')total++;
               }
           }

           for(int i = 1 ; i <= h ; i++)
           {
               int sum = 0;
               for(int j = 1 ; j <= w ; j++)
               {
                   if(maze[i][j] == '#')sum++;
               }
               row[i] = sum;
           }

           for(int i = 1 ; i <= w ; i++)
           {
               int sum = 0;
               for(int j = 1 ; j <= h ; j++)
               {
                   if(maze[j][i] == '#')sum++;
               }
               col[i] = sum;
           }

           int ans = 0;

           for(int i = 0 ; i <= (1 << h) ; i++)
           {
              vector<int> r;
              for(int k = 0 ; i >= (1 << k) ; k++)
              {
                  if(i & (1 << k))r.push_back(k + 1);
              }
              for(int j = 0 ; j < (1 << w) ; j++)
              {
                  vector<int> c;
                  for(int k = 0 ; j >= (1 << k) ; k++)
                  {
                      if(j & (1 << k))c.push_back(k + 1);
                  }

                  int sum = 0;
                  for(int a : r)sum += row[a];
                  for(int b : c)sum += col[b];
                  for(int a : r)
                  {
                      for(int b : c)
                      {
                          if(maze[a][b] == '#')sum--;
                      }
                  }

                  if(total - sum == f)ans++;
              }

           }

           cout << ans << endl;
        }
    }

