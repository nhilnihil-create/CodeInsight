#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    string s;
    cin >> s;
    ll a[s.size()]={0},i=0;
    while(i<s.size()){
        int r = 0, l = 0;
        int rp, lp;
        while(s[i]=='R'){r++; i++;}
        if(s[i]=='L'){lp = i; rp = lp-1;}
        while(s[i]=='L'){l++; i++;}
        a[rp] += (r+1)/2;
        a[lp] += r/2;
        a[lp] += (l+1)/2;
        a[rp] += l/2;
    }
    rep(i, s.size()) cout << a[i] << " ";
    cout << endl;
    return 0;
}