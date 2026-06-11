
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define sz(s) (int) s.size()
#define pb push_back
#define rc(x) return cout<<x<<"\n",0

using namespace std;
    void solve()
    {
     int n, m;
     cin >> n >> m;
     int max = m * 2 + 1;
     if (max>=n)
      cout << 1;
     else
      if (n % max == 0)
        cout << n / max;
      else
        cout << n / max + 1;
 }
               
    int main()
    {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int t=1;
      // cin>>t;
        while(t--)
        {
            solve();
        }
    }