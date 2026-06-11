#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void solve() {
        string str; cin >> str;
        bool b1= 1, b2= 1;
        int n= str.size();

        for (int i= 0; i< n/ 2; i++) {
                if (str[i]!= str[n/ 2- 1- i]) b1= 0;
        }

        for (int i= n/ 2+ 1; i< n; i++) {
                if (str[i]!= str[n- 1- i]) b1= 0;
        }

        if (b1&& b2) cout << "Yes\n";
        else cout << "No\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) solve();
return 0;
}
