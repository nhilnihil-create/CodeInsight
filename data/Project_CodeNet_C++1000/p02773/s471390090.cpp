#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    
    unordered_map<string, int> c(n);
    rep(i, n) c[s[i]] = 0;
    rep(i, n) c[s[i]]++;

    int maxC = 0;
    for(auto kv : c) {
        maxC = max(maxC, kv.second);
    } 

    vector<string> ans;
    for(auto kv : c) {
        if (kv.second == maxC) {
            ans.push_back(kv.first);
        }
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());

    rep(i, ans.size()) put(ans[i]);

    return 0;
}