#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool>    vecbool;
typedef vector<int>     vecint;
typedef vector<ll>      vecll;
typedef vector<string>  vecstr;
typedef vector<vecint>  vec2int;
typedef vector<vecbool> vec2bool;
int dx[4] {-1,+1, 0, 0};
int dy[4] { 0, 0,-1,+1};
int main()
{

  ll n; cin >> n;
  ll a = 1e9;
  ll x1 = a;
  ll x2 = a - n%a;
  ll y1 = 1;
  ll y2 = n/a + 1;
  if(n == 1e18){
    x1 = a;
    x2 = 0;
    y1 = 0;
    y2 = a;
  }
  cout <<"0 0 "<< x1<< " " << y1 << " " << x2 << " " << y2 << endl;
}
