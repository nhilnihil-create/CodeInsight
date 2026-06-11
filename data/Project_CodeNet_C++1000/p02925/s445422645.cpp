#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
typedef pair<int,int> P;

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
  set<P> s;
  multiset<P> add;
  multiset<P> new_add;
  vector<int> counts(n,0);
  rep(i,n)
  {
    int p1 = i;
    int p2 = a[i][0];
    if(p1 > p2) swap(p1,p2);
    P nowp = make_pair(p1,p2);
    if(s.find(nowp) == s.end())
    {
      s.insert(nowp);
    }
    else
    {
      s.erase(nowp);
      counts[p1]++;
      counts[p2]++;
      int q1,q2;
      q1 = a[p1][counts[p1]];
      if(p1 > q1) swap(p1,q1);
      add.insert(make_pair(p1,q1));
      q2 = a[p2][counts[p2]];
      if(p2 > q2) swap(p2,q2);
      add.insert(make_pair(p2,q2));
    }
  }
  bool ok = true;
  int day = 1;
  while(true)
  {
    day++;
    auto it = add.begin();
    while(it != add.end())
    {
      P nowp = *it;
      if(s.find(nowp) == s.end())
      {
        s.insert(nowp);
      }
      else
      {
        s.erase(nowp);
        int p1 = nowp.first;
        int p2 = nowp.second;
        counts[p1]++;
        counts[p2]++;
        if(counts[p1] < n-1)
        {
          int q1 = a[p1][counts[p1]];
          if(p1 > q1) swap(p1,q1);
          new_add.insert(make_pair(p1,q1));
        }
        if(counts[p2] < n-1)
        {
          int q2 = a[p2][counts[p2]];
          if(p2 > q2) swap(p2,q2);
          new_add.insert(make_pair(p2,q2));
        }
      }
      it++;
    }
    add.clear();
    if(new_add.size() == 0 && s.size() == 0)
    {
      break;
    }
    else if(new_add.size() == 0)
    {
      ok = false;
      break;
    }
    add = new_add;
    new_add.clear();
  }
  if(ok) cout << day << endl;
  else cout << -1 << endl;
}
