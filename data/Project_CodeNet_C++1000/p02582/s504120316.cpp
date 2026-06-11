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
    string r;
    cin >> r;
    int cnt = 0,ans = 0;
    rep(i,r.size()){
        if(r[i] == 'R') cnt++;
        else cnt = 0;
        ans = max(ans,cnt);
    }
    cout << ans << endl;
	return 0;
}