#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define repr1(i, n) for (int i = n; i > 0; i--)
#define FOR(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
const ll MOD = 1000000007; // 10^9+7
const ll INF = 100000000;

int main(void){
    int n,cnt=0;
    cin >> n;

    vector<ll> l(n,0);
    rep(i,n) cin >> l[i];

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(l[i] == l[j] || l[j] == l[k] || l[k] == l[i]) continue;
                if(abs(l[j]-l[k]) < l[i] && l[i] < l[j]+l[k]) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}