#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for (int i = 0;i < n;++i) cin >> a[i].first;
    for (int i = 0;i < n;++i) a[i].second = i;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < i+1;++j) dp[i+1][j+1] = dp[i][j]+a[i].first*abs(j-a[i].second);
        for (int j = 0;j < i+1;++j) dp[i+1][j] = max(dp[i+1][j],dp[i][j]+a[i].first*abs(n-1+j-i-a[i].second));
    }
    cout << *max_element(dp[n].begin(),dp[n].end()) << endl;
}