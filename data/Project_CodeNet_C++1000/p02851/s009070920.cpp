#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin >> n >> k;
  int a[n];
  rep(i,n)cin >> a[i];
  ll s[n+1];
  s[0]=0;
  rep(i,n)s[i+1]=s[i]+a[i];
  rep(i,n+1)s[i]-=i;
  rep(i,n+1){
    s[i]%=k;
    //if(s[i]<0)s[i]+=k;
  }
  //rep(i,n+1)cout << s[i] << endl;
  map<int,int> mp;
  ll ans = 0;
  rep(i,n+1){
    if(i<k){
      ans += mp[s[i]];
      mp[s[i]]++;
    }else{
      mp[s[i-k]]--;
      ans += mp[s[i]];
      mp[s[i]]++;
    }
  }
  cout << ans << endl;
}