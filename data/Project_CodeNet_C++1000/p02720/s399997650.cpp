#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2)

int main()
{
  int K;cin>>K;
  
  ll b[100040];
  queue<ll> q;
  ll count=1;
  for (ll i=1;i<=9;i++)
  {
    q.push(i);
    b[count]=i;
    count++;
  }
  
  while (!q.empty())
  {
    ll v = q.front();
    q.pop();
    for (ll i=-1;i<=1;i++)
    {
      ll nv = 10*v + (v%10+i);
      //cout<<nv<<endl;
      if (v%10+i>=0 && v%10+i<=9)
      {
        q.push(nv);
        b[count]=nv;
        count++;
      } 
    }
    if (count>K+1) break;
  }
  cout<<b[K]<<endl;
}