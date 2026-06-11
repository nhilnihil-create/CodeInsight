#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main() {
  ll n;
  cin>>n;
  int a[n];
  rep(i,0,n){
    cin>>a[i];
    a[i]--;
  }
  int b[n];
  rep(i,0,n) b[a[i]]=i;
  
  ll ans=0;
  set<int> s,t;
  s.insert(-1);
  s.insert(n);
  t.insert(-1);
  t.insert(n);
  rep(i,0,n){
    int c,d,e,f;
    e=*s.upper_bound(b[n-1-i]);
    if(e==n) f=n;
    else f=*s.upper_bound(e);
    d=*t.upper_bound(n-1-b[n-1-i]);
    if(d==n) c=n;
    else c=*t.upper_bound(d);
    d=n-1-d;
    c=n-1-c;
    ans+=(n-i)*((d-c)*(e-b[n-1-i])+(f-e)*(b[n-1-i]-d));
    s.insert(b[n-1-i]);
    t.insert(n-1-b[n-1-i]);
  }
  cout<<ans<<endl;
}
