#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int,int> ,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
const int N = 1e5+10 , OO = 0x3f3f3f3f , mod = 1e9 + 7;

#define PI acos(-1) 
#define clr(arr,val) memset(arr , val , sizeof (arr))
#define loop(i,n) for(int i = 0;i < int(n);i++)
#define rloop(i,n) for(int i = int(n)-1;i >= 0;i--)
#define xloop(i,a,b) for(int i = int(a);i <= int(b);i++)
#define range(vec) for(auto &x : vec) cin >> x;
#define ALL(v) ((v).begin()) , ((v).end())
#define SZ(v)  ((int)((v).size()))
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
int a,b,c,k;

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  scanf("%d %d %d %d", &a , &b , &c , &k);
  ll sum = 0; 
  if(a >= k)
    printf("%d\n", k);
  else{
    sum = a; 
    k -= a;
    if(b >= k)
      printf("%lld\n", sum);
    else{
      k -= b;
      sum -= min(c , k);
      printf("%lld\n", sum);
    }
  }
  

  return 0;
}