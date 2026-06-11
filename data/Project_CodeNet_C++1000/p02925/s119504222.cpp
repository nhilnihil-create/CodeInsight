#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define INF 1000000000

vector<int> topo_sort1(vector<vector<int>> e)
{
  int n=e.size();
  vector<int> ans(0);
  vector<int> ins(n,0);
  int i,j;
  rep(i,n)
  {
    rep(j,e[i].size())
    {
      ins[e[i][j]]++;
    }
  }
  queue<int> s;
  rep(i,n) if(ins[i]==0)s.push(i);
  while(!s.empty())
  {
    int now=s.front();
    s.pop();
    ans.emplace_back(now);
    rep(i,e[now].size())
    {
      ins[e[now][i]]--;
      if(ins[e[now][i]]==0)
      {
        s.push(e[now][i]);
      }
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n-1));
  int i,j;
  rep(i,n)rep(j,n-1)
  {
    cin >> a[i][j];
    a[i][j]--;
  }
  vector<vector<int>> e(n*(n-1)/2);
  vector<vector<int>> trans(n,vector<int>(n,-1));
  int num = 0;
  rep(i,n)rep(j,i)
  {
    trans[j][i] = num;
    trans[i][j] = num;
    num++;
  }
  rep(i,n)rep(j,n-2)
  {
    int from = trans[i][a[i][j]];
    int to = trans[i][a[i][j+1]];
    e[from].emplace_back(to);
  }
  vector<int> ans;
  ans = topo_sort1(e);
  if(ans.size() < n*(n-1)/2)
  {
    cout << -1 << endl;
  }
  else
  {
    vector<int> dp(n*(n-1)/2,1);
    for(i=n*(n-1)/2-1;i>=0;i--)
    {
      rep(j,e[ans[i]].size())
      {
        dp[ans[i]] = max(dp[ans[i]], dp[e[ans[i]][j]]+1);
      }
    }
    int ans = 0;
    rep(i,n*(n-1)/2)
    {
      ans = max(ans,dp[i]);
    }
    cout << ans << endl;
  }
}
