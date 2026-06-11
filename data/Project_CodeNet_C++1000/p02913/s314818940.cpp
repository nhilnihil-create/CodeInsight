#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


vector<int> Zalgo(string s){
    int n = s.size();
    vector<int> a(n, 0);
    int from = -1, last = -1;
    for(int i = 1; i < n; i++){
        int &same = a[i];
        if (from != -1){
            same = min(a[i-from], last - i);
            same = max(same, 0);
        } 
        while(same+i < s.size() && s[same] == s[i+same]) same++;
        if (last < i+same) {
            last = i + same;
            from = i;
        }
    }
    a[0] = n;
    return a;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i, n-1){
        string t = s.substr(i);
        vector<int> a = Zalgo(t);
        rep(i, a.size()) {
            // cout << a[i] << " ";
            if (a[i] >= i+1) continue;
            ans = max(a[i], ans);
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}

