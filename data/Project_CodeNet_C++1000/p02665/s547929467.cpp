#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n;cin>>n;
  vector<ll> a(n+1),limit(n);
  rep(i, n+1)cin>>a[i];

  if(n==0){
    if(a[0]==1)cout<<1<<endl;
    else cout<<-1<<endl;
    return 0;
  }

  limit[n-1]=a[n]+a[n-1];
  rrep(i, n-1){
//cout<<limit[i+1]<<' '<<a[i]<<endl;
    limit[i] = limit[i+1]+a[i];
  }
  limit.push_back(a.back());

//  for(auto c:limit)cout<<c<<' ';cout<<endl;

  ll result = 1;
  ll l=1;

  if(a[0]==1 && n>0) { cout<<-1<<endl; return 0; }

  rep(i, n){
    ll c=a[i];

    ll nl = min<ll>((l-c)*2, limit[i+1]);
    if(l-c<0 || nl-a[i+1]<0) { 
//cout<<nl<<'-'<<a[i+1]<<endl;
cout<<-1<<endl; return 0;}
    if(l==0 && a[i]>0) { cout<<-1<<endl; return 0;}

    if(i<n-1)result += nl;
//cout<<l<<' '<<c<<' '<<l-c<<' '<<nl<<' '<<result<<endl;
    swap(l, nl);
  }
//cout<<l<<endl;
  if(a.back()>limit.back() || a.back()>l) { cout<<-1<<endl; return 0; }

  cout<<result+a.back()<<endl;

  return 0;
}
