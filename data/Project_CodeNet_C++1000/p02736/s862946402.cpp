#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  ll n; cin >> n;
  string s; cin >> s;
  vector<ll> b(n);
  bool f1=0;
  rep(i,n){
    b[i]=ll(s[i]-'0');
  }
  vector<ll> a(n-1);
  rep(i,n-1){
    a[i]=abs(b[i]-b[i+1]);
    if(a[i]==1) f1=1;
  }
  n--;
  ll sum=0;
  rep(i,n){
    if(n-1==(i|(n-1-i))) sum+=a[i]%2;
  }
  if(sum%2==1){
    cout << 1 << endl;
    return 0;
  }
  if(f1){
    cout << 0 << endl;
    return 0;
  }
  rep(i,n){
    a[i]/=2;
  }
  sum=0;
  rep(i,n){
    if(n-1==(i|(n-1-i))) sum+=a[i]%2;
  }
  if(sum%2==1){
    cout << 2 << endl;
    return 0;
  }
  cout << 0 << endl;
}