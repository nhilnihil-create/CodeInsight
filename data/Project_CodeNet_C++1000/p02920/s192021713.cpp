#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(v) ((ll)v.size())
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define F first
#define S second
#define pii pair<ll,ll> 
const ll mod = 1000000007;
const ll mod1= 1000000009;
const ll base= 2323233;
const ll base1=3424424;
#define MAXN 2000004
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
ll a[3000002];
bool cmp(const pair<pii,ll> &x,const pair<pii,ll> &y){
  if(x.F.F==y.F.F) return x.F.S>y.F.S;
  return x.F.F<y.F.F;
}
ll L[100002][2], R[100002][2];
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll n,i;
   cin>>n;
   multiset<ll> s;
   for(i=1;i<=(1<<n);i++) {
    cin>>a[i];
    s.insert(-a[i]);
   }
   sort(a+1,a+1+(1<<n));
   reverse(a+1,a+1+(1<<n));
   vector<ll> v;
   v.pb(a[1]);
   s.erase(s.find(-a[1]));
   while(v.size()<(1<<n)){
    ll nn=v.size();
    for(i=0;i<nn;i++){
      auto it=s.upper_bound(-v[i]);
       if(it==s.end()){
        cout<<"No";
        return 0;
       }
      s.erase(it);
      v.pb(-(*it));
    }
   }
   cout<<"Yes";
 }
