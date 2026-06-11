#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    set<int> divisors;
    for(int i = 1; i*i <= sum; i++){
        if(sum % i == 0){
            divisors.insert(i);
            divisors.insert(sum/i);
        }
    }
    int ans = 1;
    for(auto x: divisors){
        vector<int> rem(n);
        for(int i = 0; i < n; i++) rem[i] = a[i] % x;
        sort(rem.begin(), rem.end());
        int tot = 0;
        for(int i = 0; i < n; i++) tot += rem[i];
        int idx = n - tot / x;
        int tmp = 0;
        for(int i = 0; i < idx; i++){
            tmp += rem[i];
        }
        if(tmp <= k) ans = max(ans, x);
    }
    cout << ans << endl;
}