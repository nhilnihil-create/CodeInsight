#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};     

int w, h;
bool data[51][51];

void dfs( int y, int x )
{
  data[y][x] = 0;

  Rep(i, 8) {
    int nx = x + dx[i], ny = y + dy[i];
    if( nx < 0 || nx >= w || ny < 0 || ny >= h || !data[ny][nx] ) continue;
    dfs( ny, nx );
   }
}


main()
{
  while( cin >> w >> h, !(w == 0 && h == 0) ) {
    
    Rep(i, h) Rep(j, w) cin >> data[i][j];

    int cnt = 0;
    Rep(i, h) Rep(j, w) {
      if( data[i][j] ) dfs(i, j), cnt++; 
    }

    cout << cnt << endl;
  }
   
}