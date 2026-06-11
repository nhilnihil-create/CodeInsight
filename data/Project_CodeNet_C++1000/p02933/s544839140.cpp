#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define strall(v) (v).cbegin(),(v).cend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
//const long long INF = 1LL << 60;
 int INF = 500000;
 int MAX = 2050;
 ll mod = 1e9+7;

int main(){
  int a;
  string s;
  cin >> a >> s;
  cout << ((a >= 3200) ? s:"red") << endl;
}