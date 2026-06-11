#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        sort(t.begin(),t.end());
        s[i]=t;
    }
    sort(s.begin(),s.end());
    
    string x=s[0];
    vector<int> b(n);
    int y=0;
    b[y]=1;
    for(int i = 1; i < n; i++) {
        if(x==s[i]) b[y]++;
        else{
            x=s[i];
            y++;
            b[y]=1;
        }
    }

    ll ans=0;
    for(int i = 0; i < n; i++) {
        ll p = b[i];
        p *= b[i]-1;
        p /= 2;

        ans += p;
    }

    cout << ans << endl;

    return 0;
}