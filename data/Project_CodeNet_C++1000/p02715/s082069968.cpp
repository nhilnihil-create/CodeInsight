#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
typedef  long long     ll ;
typedef  unsigned long long ull;
const double EPS= (1e-9);
using namespace std;
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(int num, int idx) {return num ^ (1<<idx);}
void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=100000+9,mod=1000000000+7;
ll cnt[N],fres[N];
int go(int n){

   for(int i=1;i*i<=n;i++){

       if(n%i==0){
         cnt[i]++;
         if(n/i!=i) cnt[n/i]++;
       }

   }
  return 0;
}
ll power(ll b,ll p){

   if(p==0) return 1;
   if((p&(1ll))){
     return b%mod*power((b*b)%mod,p/2)%mod;
   }
   else{
    return  power((b*b)%mod,p/2);
   }
}
int main(){
    GO();
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        go(i);
    }
    ll ans=0;
    for(int i=k;i>=1;i--){
        fres[i]=power(cnt[i],n);
         for(int j=i*2;j<=k;j+=i){
            fres[i]=((fres[i]-fres[j])+mod)%mod;
         }
         ans+= (1ll*fres[i]*i)%mod;
         if(ans>=mod) ans-=mod;

    }
   cout<<ans<<"\n";
}


































