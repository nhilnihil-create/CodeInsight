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

ll K;
vector<ll> all;

void rec(ll n)
{
   for (ll i=-1;i<=1;i++)
   {
     if (n%10+i>=0 && n%10+i<=9)
     {
       if (10*n + n%10+i>0)
       {
         all.push_back(10*n + n%10+i);
         rec(10*n + n%10+i);
         if (10*n + n%10+i >= 3500000000) return;
       }
     }
   }
}
   
int main()
{
  cin>>K;
  for (ll i=1;i<=9;i++)
  {
    all.push_back(i);
    rec(i);
  }
  
  sort(all.begin(),all.end());
  cout<<all[K-1]<<endl;
}