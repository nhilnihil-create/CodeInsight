#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    rep(i, 0, m) cin >> p[i] >> s[i];
    map<int, bool> mp;
    vector<int> a(n+1);
    int ac = 0;
    int wa = 0;
    rep(i, 0, m){
        if(mp[p[i]] == false && s[i] == "AC"){
            mp[p[i]] = true;
            ac++;
            wa += a[p[i]];
        }
        if(mp[p[i]] == false && s[i] == "WA"){
            a[p[i]]++;
        }
    }
    cout << ac << " " << wa << endl;
    return 0;
}
