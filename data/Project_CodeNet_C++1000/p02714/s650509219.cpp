#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> color(3,0);
    rep(i,n){
        if(s[i] == 'R') color[0]++;
        if(s[i] == 'G') color[1]++;
        if(s[i] == 'B') color[2]++;
    }
    ll count = 0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            int k = 2*j - i;
            if(k >= n) continue;
            if(s[i]!=s[j] && s[j]!=s[k] && s[k]!=s[i]) count++;
        }
    }
  	ll ans = color[0]*color[1]*color[2] - count;
    cout << ans << endl;
}