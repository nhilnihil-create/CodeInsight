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
    int m; cin >> m;
    V<int> a(m + 1);
    for(int i = 1; i <= m; i++) cin >> a[i];

    V<int> ans;
    V<int> cnt(m + 1, 0);
    for(int i = m; i > 0; i--){
        int c = 0;
        for(int j = i; j <= m; j+=i){
            if(cnt[j]) c++;
        }
        if(a[i] == 1 && c % 2 == 0){
            cnt[i] = 1;
            ans.push_back(i);
        }
        if(a[i] == 0 && c % 2 == 1){
            cnt[i] = 1;
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}
