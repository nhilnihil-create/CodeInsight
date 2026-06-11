#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;

int main()
{
  fastio;
  int n,m;
  cin>>n>>m;
  priority_queue<int> q;
  range(i,0,n)
  {
    int x;
    cin>>x;
    q.push(x);
  }
  while(m>0)
  {
    int t=q.top();
    q.pop();
    t/=2;
    m--;
    q.push(t);
  }
  ll sum=0;
  while(!q.empty())
  {
    sum+=q.top();
    q.pop();
  }
  cout<<sum;
}
