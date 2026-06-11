#include <bits/stdc++.h>  // ver2.1.9
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define Pii pair<int,int>
#define Tiii tuple<int,int,int>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lW,0,a.size()){Vout(a[lW]);}
#define INF 9000000000000000000  //  9.0 * 10^18
#define MOD 1000000007  //  10^9 + 7
using namespace std;
 
int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
void uniq(Vi &v){sort(ALL(v)); v.erase(unique(ALL(v)),v.end());}  //  uniqのやつ
 
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
 
signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(16);
  int n,qw,er;
  cin >> n;
  vector<Pii> a(n);
  rep(i,0,n){
    cin >> qw >> er;
    a[i] = mp(qw,er);
  }
  
  Pii memo;
  int ct = 0;
  map<Pii,int> kind;
  rep(i,0,n){
    rep(j,i+1,n){
      memo = mp(a[i].first-a[j].first,a[i].second-a[j].second);
      kind[memo]++;
      memo = mp(a[j].first-a[i].first,a[j].second-a[i].second);
      kind[memo]++;
    }
  }
  int maxx=0;
  for (auto p : kind ) {
    auto k = p.first;
    auto v = p.second;
    maxx = max(maxx,v);
  }
  cout << n-maxx << endl;
  
  return 0;
}