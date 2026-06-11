#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll t1,t2;cin>>t1>>t2;
  ll a1,a2,b1,b2;
  cin>>a1>>a2>>b1>>b2;
  ll p = (a1-b1)*t1;
  ll q = (a2-b2)*t2;
  if(p>0){p*=-1;q*=-1;}
  if(p+q < 0)cout<<0<<endl;
  else if(p+q == 0)cout<<"infinity"<<endl;
  else{
    ll s = -p/(p+q);
    ll t = -p%(p+q);
    if(t == 0){
      cout<<s*2<<endl;
    }else cout<<s*2+1<<endl;
  }
  return 0;
}
