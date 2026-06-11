#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  int i;
  rep(i,n) cin >> p[i];
  vector<int> ind(n);
  rep(i,n)
  {
    ind[p[i]-1] = i;
  }
  multiset<int> s;
  s.insert(-1);
  s.insert(-1);
  s.insert(n);
  s.insert(n);
  ll ans = 0;
  int num;
  for(num=n-1;num>=0;num--)
  {
    int j = ind[num];
    auto it = s.upper_bound(j);
    int a,b,c,d;
    it++;
    d = *it;
    it--;
    c = *it;
    it--;
    b = *it;
    it--;
    a = *it;
    ll ks = 0;
    ll kans = b-a;
    kans *= (c-j);
    ks += kans;
    kans = j-b;
    kans *= (d-c);
    ks += kans;
    ans += ks*(num+1);
    s.insert(j);
  }
  cout << ans << endl;
}
