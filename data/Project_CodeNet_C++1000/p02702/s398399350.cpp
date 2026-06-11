#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    ll cur=0, ans=0, ten=1;
    map<int, int> freq;
    freq[0]=1;
    for (int i=s.size()-1; i>=0; --i) {
        cur+=1LL*(s[i]-'0')*ten;
        cur%=2019;
        ten*=10;
        ten%=2019;

        ans+=freq[cur];
        ++freq[cur];
    }

    cout << ans;

    return 0;
}
