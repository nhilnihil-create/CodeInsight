#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int main()
{
    string s;
    cin >> s;
    int N = s.size();
    vector<ll> h(N, 1);
 //   rep(i, N) cout << h[i]  <<" " ;
//    cout << endl;
    
    ll x = -1;
    ll r = 0;
    ll l = 0;
    rep(i, N)
    {
      if(s[i] == 'R')
      {
        if(x >= 0)
        {
            int d = l+r;
            h[x] = d/2+d%2;
            h[x+1] = d/2;
            if((i-x)%2 == 0)
            {
                swap(h[x], h[x+1]);
            }
            x = -1;
            l = 0;
            r = 0;
        }
        h[i] = 0;
        ++r;  
      }
      if(s[i] == 'L')
      {
        if(i>=1 && s[i-1] == 'R') x = i-1;
        h[i] = 0;
        ++l;
      }
    }
    if(x >= 0)
    {
        int i = N-2;
        int d = l+r;
        h[x] = d/2+d%2;
        h[x+1] = d/2;
        if((i-x)%2 == 0)
            {
                swap(h[x], h[x+1]);
            }
    }
    rep(i, N) cout << h[i]  <<" " ;
    cout << endl;
    return 0;
}