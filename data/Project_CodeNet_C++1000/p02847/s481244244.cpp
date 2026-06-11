#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  if(s=="SUN") cout << "7" << endl;
  else if(s=="MON") cout << "6" << endl;
  else if(s=="TUE") cout << "5" << endl;
  else if(s=="WED") cout << "4" << endl;
  else if(s=="THU") cout << "3" << endl;
  else if(s=="FRI") cout << "2" << endl;
  else if(s=="SAT") cout << "1" << endl;
  return 0;
}
