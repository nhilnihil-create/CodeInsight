#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  ll ans = 1000;
  for(auto &a:A)cin>>a;
  for(int i=0;i<n-1;i++){
    if(A[i] < A[i+1]){
      ll num = ans/A[i];
      ans = ans%A[i] + num * A[i+1];
    }
  }
  cout<<ans<<endl;
  return 0;
}
