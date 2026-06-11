    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void solve() {
        string s;
        cin >> s;
        s = '0'+s;
        ll cnt = 0, c = 0;
        for(ll i = s.length() - 1; i >= 0; i--){
            ll val = (s[i] - '0') + c;
            cnt+= min(val, 10 - val);
            c = (val > 5 || (val == 5 && s[i-1] >= '5'));
        }
        cout << cnt + c<< endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //ll ti;   cin >> ti;  while(ti--)
      solve();
      return 0;
    }
