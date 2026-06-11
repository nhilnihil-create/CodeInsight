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
const int N=1000000+5,mod=1e9+7;
int a[N],L[N];
int S[N];
bool vis[N];
vector<int> v[N];
void seive(int num){
  for(int i=1;i<=num;i++) L[i]=i;
   vis[0]=vis[1]=1;
   for(int i=2;1ll*i*i<=num;i++){
    if(vis[i]) continue;
    L[i]=i;
    for(int j=i*2;j<=num;j+=i){
        vis[j]=1;
        L[j]=min(L[j],i);
    }
   }

}
void get_fact(int num){
   int onum=num;
   bool fl=0;
   if(sz(v[onum])!=0) fl=1;
   while(num>1){

      S[L[num]]++;
      if(fl==0)
      v[onum].pb(L[num]);

      num/=L[num];
   }

}
int main(){
    GO();

   int T;
   // cin>>T;
   T=1;
    while(T--){
       int n;
       cin>>n;
       seive(1000000);

       ll gg=0;
       for(int i=0;i<n;i++){
         cin>>a[i];
         get_fact(a[i]);
         gg=__gcd(gg,a[i]*1ll);
       }
       bool ok=1;
       for(int i=0;i<n&&ok;i++){

           for(int j=0;j<sz(v[a[i]]);j++){
            int val= v[a[i]][j];
            S[val]--;
           }
           for(int j=0;j<sz(v[a[i]])&&ok;j++){
            int val= v[a[i]][j];
            if(S[val]>0){
                ok=0;
            }
           }

       }
       if(ok){
        cout<<"pairwise coprime\n";
       }
       else if(gg==1){
        cout<<"setwise coprime\n";
       }
       else{
        cout<<"not coprime\n";
       }

    }

}





























































































