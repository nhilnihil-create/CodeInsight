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
  int n,m; cin >> n >> m;
  if(n%2==1){
    rep(i,m){
      cout << i+1 << " " << n-(i+1) << endl;
    }
  }
  else{
    set<int> st;
    rep(i,m){
      if(st.count(n-2*i-1)||n-2*i-1==2*i+1) n--;
      cout << i+1 << " " << n-i << endl;
      st.insert(n-2*i-1);
      st.insert(2*i+1);
    }
  }
}