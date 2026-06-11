#include <bits/stdc++.h>
using namespace std;
#define pr(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

const int N= 200001;

void solve() {
        int n, m, k; cin >> n>> m>> k;

        vector<int> vn(n), vm(m);

        for (auto& i: vn) cin >> i;
        for (auto& i: vm) cin >> i;

        vector<int> nsum(n+ 1, 0), msum(m+ 1, 0);
        for (int i= 1; i<= n; i++) nsum[i]= nsum[i- 1]+ vn[i- 1];
        for (int i= 1; i<= m; i++) msum[i]= msum[i- 1]+ vm[i- 1];

        int mx= 0;

        for (int i= 0; i<= n; i++) {
                int cnt= nsum[i];
                if (cnt> k) break;
                int pos= upper_bound(all(msum), (k- cnt))- msum.begin();
                mx= max(mx, i+ pos- 1);
        }

        cout << mx<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
