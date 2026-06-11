#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;
int main(){
  ll n;
  cin>>n;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  int m=ceil(sqrt(n))+1;
  vector<int> index(m);
  rep2(i,2,m){
    while(n%i==0){
      n/=i;
      index[i]++;
    }
  }
 int ans=0;
 rep(i,m){
   rep(j,45){
     if(j*(j+1)/2<=index[i]&&index[i]<(j+1)*(j+2)/2){
       ans+=j;
       break;
     }
   }
 }
  if(n>1) ans++;
  cout<<max(1,ans)<<endl;
return 0;
}