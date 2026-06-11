#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) FOR(i,0,b)
#define INF mugen
#define dump(x) cerr<<#x<<"="<<x<<endl
#define ALL(a) (a).begin(),(a).end()
#define EACH(e,v) for(auto& e:v)
#define SORT(v) sort(ALL(v))
#define PERM(v) SORT(v);for(bool c##p=1;c##p;c##p=next_permutation(ALL(v)))
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<int,int> P;
template <class T> void chmin(T & a, T const & b) { if (b < a) a = b; }
template <class T> void chmax(T & a, T const & b) { if (b > a) a = b; }
template <typename T>
string to_string(const T &n){ostringstream stm;stm << n;return stm.str();}
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
using ll = long long;
const ll mod = 1000'000'007;
 
signed main(){
 int n;
 cin>>n;
 cout<<(n%2==0 ? n/2-1 : n/2)<<endl;
}