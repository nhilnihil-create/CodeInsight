#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    V<int> v(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        v[i] = a;
        sum += a;
    }

    if(v[0] == 1 && sum % 2 != 0){
        cout << -1 << endl;
        return 0;
    }

    V<int> ans(n + 1, 0);
    int cnt = 0;
    for(int i = n; i > 0; i--){
        int sum = 0, j = i;
        while(j <= n){
            sum += ans[j];
            j += i;
        }
        if((v[i] && sum % 2 == 0) || (v[i] == 0 && sum % 2 != 0)){
            ans[i]++;
            cnt++;
        }
    }

    V<int> ans2;
    for(int i = 1; i <= n; i++){
        if(ans[i]) ans2.push_back(i);
    }
    cout << cnt << endl;
    for(int i = 0; i < (int)ans2.size(); i++){
        if(i != (int)ans2.size() - 1) cout << ans2[i] << " ";
        else cout << ans2[i] << endl;
    }
}
