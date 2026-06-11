#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

const int N= 200001;
int freq[N];

void solve() {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i: v) {
                cin >> i;
                freq[i]++;
        }

        int an= 0;
        for (int i= 0; i<= n; i++) {
                an+= freq[i]* (freq[i]- 1)/ 2;
        }

        int cur= 0;
        for (int i= 0; i< n; i++) {
                cur= an;
                int nm= v[i];

                cur-= freq[nm]* (freq[nm]- 1)/ 2;
                cur+= (freq[nm]- 1)* (freq[nm]- 2)/ 2;
                cout << cur<< "\n";
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) solve();
return 0;
}
