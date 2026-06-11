#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional> // for less
//using namespace __gnu_pbds;
using namespace std;
typedef long long  L;

#define max_(x, y) (((x) > (y)) ? (x) : (y))
#define min_(x, y) (((x) < (y)) ? (x) : (y))
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define Mx 2000001
#define inf 1e15
const L MOD = 1e9+7;
const double pi = 2 * acos (0.0);

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


//typedef tree<L,null_type,less<L>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

L a1,a2,a3,b1,b2,b3,c,c1,c2,c3,d,d1,d2,d3,d4,d5,e1,e2,e3,f,h,k,l,m,n,m1,m2,n1,n2,o,p,p1,p2,p3,p4,
q,q1,q2,q3,q4,r,s,t,u,v,x,y,z,sum,mx=-inf,mn=inf,flg,flg1,flg2,id1,id2,id3,id4,lim;

L A[Mx];

bool isValid(L X){
  c=k;
  for(L i=0;i<n;i++){
    d=(A[i]/X);
    if(A[i]%X)d++;
    d--;
    if(c<d)return false;
    c=c-d;
  }
  return true;
}
void solve(){
  l=1;r=1e9;
  L mid;
  while(l<=r){
    mid=(l+r)/2;
    if(isValid(mid)){
      c1=mid;
      r=mid-1;
    }else{
      l=mid+1;
    }
  }
  printf("%lld\n",c1);
}
int main()
{
    scanf("%lld%lld",&n,&k);
    for(L i=0;i<n;i++){
      scanf("%lld",&A[i]);
    }
    solve();
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
