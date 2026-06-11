#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sort(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int main(){
  int n; cin >> n;
  ll money=1000;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  vector<int> b(0);
  vector<int> s(0);
  if(v[0]<v[1]) b.push_back(0);
  rep1(i,n-2){
    if(v[i-1]<v[i]&&v[i]>=v[i+1]) s.push_back(i);
    if(v[i-1]>=v[i]&&v[i]<v[i+1]) b.push_back(i);
  }
  if(v[n-2]<v[n-1]) s.push_back(n-1);
  rep(i,b.size()){
    if(upper_bound(all(s),b[i])!=s.end()){
      money=money%v[b[i]]+money/v[b[i]]*v[*upper_bound(all(s),b[i])];
    }
  }
  cout << money << endl;
}