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
  vector<ll> a(n+1);
  rep(i, n+1)cin>>a[i];

  if(n==0 && a[0]!=1) { cout<<-1<<endl; return 0; }
  if(n!=0 && a[0]!=0) { cout<<-1<<endl; return 0; }

  vector<ll> limit(n+1);
  limit[n] = a.back();
  rrep(i, n){
    limit[i]=a[i]+limit[i+1];
  }

  ll result=0;
  ll now=1;
  rep(i, n+1){
    result += now;
    now -= a[i];
    if(now<0) { cout<<-1<<endl; return 0; }
    now = min<ll>(now*2, limit[i+1]);
  }

  cout<<result<<endl;

  return 0;
}
