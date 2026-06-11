#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    int dp1[n],dp2[n], now = -1;
    for(int i=0;i<n;i++){
    	if(s[i] == 'x') dp1[i] = -1;
    	else if(now == -1)dp1[i] = 1, now = i;
    	else if(i - now > c) dp1[i] = dp1[now] + 1, now = i;
    	else dp1[i] = -1;
    }
    now = n;
    for(int i=n-1;i>=0;i--){
    	if(s[i] == 'x') dp2[i] = -1;
    	else if(now == n) dp2[i] = k, now = i;
    	else if(now - i > c) dp2[i] = dp2[now] - 1, now = i;
    	else dp2[i] = -1;
    }
    vector<int> v;
    for(int i=0;i<n;i++){
    	if(dp1[i] != -1 && dp2[i] != -1 && dp1[i] == dp2[i]){
    		v.pb(i+1);
    	}
    }
    for(int i: v) cout << i << endl;
    return 0;
}
