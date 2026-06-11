#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(V) V.begin(), V.end()
#define PB push_back
using namespace std;
typedef long long ll;

int main() {
    string s,t;
    cin>> s >> t;
    int cnt = 0;
    rep(i,s.size()) if(s[i] != t[i]) cnt++;
    cout << cnt << endl;
}