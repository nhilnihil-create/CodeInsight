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

int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  ll length=0;
  rep(i,n) length+=a[i];
  ll min=INF;
  ll temporarylength=0;
  rep(i,n){
temporarylength+=a[i];
    if(abs(length-2*temporarylength)<min) min=abs(length-2*temporarylength);
  }
  cout<<min<<endl;
return 0;
}
