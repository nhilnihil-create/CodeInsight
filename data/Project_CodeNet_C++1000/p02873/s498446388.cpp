//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    string s;
    cin >> s;

    queue<int> mi;
    vi sum(s.size()+1);
    rep(i, s.size()) {
        if(s[i] == '>') {
            sum[i+1] = sum[i]-1;
            if(i == s.size()-1 || s[i+1] == '<' ) {
                mi.push(sum[i+1]);
            }
        } else {
            if(!i) {
                mi.push(0);
            }
            sum[i+1] = sum[i]+1;
        }
    }

    int i = 0;
    int now = -mi.front();
    mi.pop();
    while(i != s.size()+1) {
        if(i && i != s.size() && s.substr(i-1, 2) == "<>") {
            sum[i] += max(now, -mi.front());
            now = -mi.front();
            mi.pop();
            ++i;
            continue;
        }
        sum[i] += now;
        ++i;
        //cout << now << endl;
    }

    ll ans = 0LL;
    rep(i, s.size()+1) {
        ans += sum[i];
    }

    cout << ans << endl;
    
}