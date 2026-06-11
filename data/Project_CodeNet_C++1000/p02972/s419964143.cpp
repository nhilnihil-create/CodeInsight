#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<int> a(n + 1);
    for(int i = 0; i < n; i++) cin >> a[i + 1];

    V<int> b(n + 1);
    for(int i = n; i > 0; i--){
        int sum = a[i];
        for(int j = i + i; j <= n; j+=i){
            sum += b[j];
        }
        b[i] = sum % 2;
    }

    V<int> ans;
    for(int i = 1; i <= n; i++){
        if(b[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i != ans.size() - 1) cout << ans[i] << ' ';
        else cout << ans[i] << endl;
    }

    return 0;
}
