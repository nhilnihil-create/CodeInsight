#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

using namespace std;

typedef long long ll;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pb_ds;

#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define pi pair<int,int>
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define mod 1000000007
#define pai acos(-1)
#define N 105

int n,m;
int ar[N][N],dis[N][N];
int fx[]={0,1};
int fy[]={1,0};

bool valid(int x,int y){
   return x>=1&&x<=n&&y>=1&&y<=m;
}

int bfs(int x,int y){
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++) dis[i][j]=INT_MAX;
   }
   deque<pi>q;
   q.push_back({x,y});
   dis[x][y]=ar[x][y];
   while(!q.empty()){
      pi u=q.front();q.pop_front();
      for(int i=0;i<2;i++){
         int nx=u.F+fx[i];
         int ny=u.S+fy[i];
         if(valid(nx,ny)){
            int c=(!ar[u.F][u.S]&&ar[nx][ny])?1:0;
            if(dis[nx][ny]>dis[u.F][u.S]+c){
               dis[nx][ny]=dis[u.F][u.S]+c;
               if(c) q.push_back({nx,ny});
               else q.push_front({nx,ny});
            }
         }
      }
   }
   return dis[n][m];
}


int main ()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         char c;cin>>c;
         ar[i][j]=(c=='#')?1:0;
      }
   }
   cout<<bfs(1,1)<<endl;
   return 0;
}

