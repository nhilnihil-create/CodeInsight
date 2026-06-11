#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define     PI                       acos(-1)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-9);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int N=5000+5,mod=1e9+7;
int n,k,p[N],c[N];
ll arr[N];
ll solve(int no){

   int str=no;
   int rem=k,cnt=0;
   ll ret=0,mx=-1e16;
   arr[cnt]=0;
   while(rem>0){
    str=p[str];
    rem--;
    ret+= c[str];
    mx=max(mx,ret);
    cnt++;
    arr[cnt]=mx;
    if(str==no){
        break;
    }
   }
   ll mx2=mx;
   if(rem>0){
    int F= rem/cnt;
    int mo= rem%cnt;
    mx=max(mx,ret*(F+1)+arr[mo]);
    mx=max(mx,(F)*ret+mx2);
   }
  return mx;
}
int main(){

    GO();
    int T;
    T=1;
    while(T--){

        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        ll ans=-1e16;
        for(int i=1;i<=n;i++){
            ans=max(ans,solve(i));
        }
        cout<<ans<<"\n";
    }
}













































































































































































































































