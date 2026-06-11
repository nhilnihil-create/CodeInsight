#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int N = 2e5 + 10, OO = 0x3f3f3f3f, mod = 1e9 + 7;

#define PI acos(-1)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(v) ((v).begin()), ((v).end())
#define SZ(v) ((int)((v).size()))
//int dx[] = {1, 0, -1, 0};
//int dy[] = {0, 1, 0, -1}; //4 Direction
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int n,m,k;
char grid[10][10];

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  scanf("%d %d %d", &n , &m , &k);
  for(int i = 0 ; i < n ; ++i)
    scanf("%s" , grid[i]);
    
  int ans = 0 , cnt = 0;
  for(int mskR = 0 ; mskR < (1 << n) ; ++mskR){
    for(int mskC = 0 ; mskC < (1 << m) ; ++mskC){
      cnt = 0;
      for(int i = 0 ; i < n ; ++i){
        if(mskR & (1 << i)){
          for(int j = 0 ; j < m ; ++j){
            if(mskC & (1 << j)){
              cnt += (grid[i][j] == '#');
            }
          }
        }
      }
      ans += (cnt == k);
    }
  }

  printf("%d\n" , ans);

  return 0;
}
