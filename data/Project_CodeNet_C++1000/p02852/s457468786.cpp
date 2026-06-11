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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> ans;

    int p = n;
    while(p > 0){
        int a = p;
        loop(i,1,m+1){
            if(p-i == 0){ a = 0; break; }
            if(s[p-i] == '0') a = p-i;
        }
        if(a == p){ cout << -1 << endl; return 0; }
        ans.push_back(p-a); p = a;
    }

    int ss = ans.size();
    rep(i,ss) cout << ans[ss-1-i] << " ";
    return 0;
}
