#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;
 
int main() {
    int n;
    cin >> n;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                ll ma = max({l[i],l[j],l[k]});
                ll sum = l[i]+l[j]+l[k]-ma;
                if(sum > ma && l[i] != l[j] && l[j] != l[k] && l[k] != l[i]) cnt++;
            }
        }
    }
    cout << cnt << endl;
	return 0;
}