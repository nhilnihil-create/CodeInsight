#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LL long long int 
const LL MOD=2019;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.
LL l,r;
bool check(LL i){
  LL x=l/2019;
  x*=2019;
  if((l<=x+i&&x+i<=r)||(l<=x+i+2019&&x+i+2019<=r)) return 1;
  return 0;
}
bool check1(LL i){
  LL x=l/2019;
  x*=2019;
  LL a=0;
  if((l<=x+i&&x+i<=r)) a++;
  if((l<=x+i+2019&&x+i+2019<=r)) a++;
  if((l<=x+i+2*2019&&x+i+2*2019<=r)) a++;
  if(a>=2) return 1;
  else return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    int t=1;//cin>>t;
    while(t--){
      LL i,j,ans=1e18;cin>>l>>r;
      fo(i,0,2019){
        fo(j,0,2019){
          if(i!=j){
            if(check(i)&&check(j)){
              ans=min(ans,i*j%MOD);
            }
          }
          else{
            if(check1(i)){
              ans=min(ans,i*i%MOD);
            }
          }
        }
      }
      cout<<ans;
    }
    return 0;
}