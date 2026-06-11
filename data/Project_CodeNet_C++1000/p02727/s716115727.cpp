#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

ll max3(ll a,ll b,ll c)
{
  return max(max(a,b),c); 
}

int main()
{
  ll X,Y,A,B,C;
  cin>>X>>Y>>A>>B>>C;
  ll pp,qq,rr;
  priority_queue<ll, vector<ll>> p;
  priority_queue<ll, vector<ll>> q;
  priority_queue<ll, vector<ll>> r;
  for (int i=0;i<A;i++)
  {
    cin>>pp;
    p.push(pp);
  }
  for (int i=0;i<B;i++)
  {
    cin>>qq;
    q.push(qq);
    
  }
  for (int i=0;i<C;i++)
  {
    cin>>rr;
    r.push(rr);
  }
  
  //priority_queue<ll, vector<ll>, greater<ll> > q;
  
  ll ans = 0;
  ll i=0;
  ll j=0;
  ll k=0;
  while (k<X+Y)
  {
    pp=p.top();
    qq=q.top();
    rr=r.top();
    
    if (p.empty() || i>=X) pp = -1;
    if (q.empty() || j>=Y) qq = -1;
    if (r.empty()) rr = -1;
    
    if (i<X && pp==max3(pp,qq,rr))
    {
      ans += pp;
      //cout<<"p"<<pp<<endl;
      p.pop();
      i++;
    }
    else if (j<Y && qq==max3(pp,qq,rr))
    {
      ans += qq;
      //cout<<"q"<<qq<<endl;
      q.pop();
      j++;
    }
    else if (rr==max3(pp,qq,rr))
    {
      ans += rr;
      //cout<<"r"<<rr<<endl;
      r.pop();
    }
    k++;
  }

  cout<<ans<<endl;
}