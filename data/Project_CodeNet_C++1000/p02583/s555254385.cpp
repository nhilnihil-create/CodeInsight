#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n)cin >> l[i];

    sort(all(l));
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                if(l[i] != l[j] && l[j] != l[k] && l[k]+l[j] > l[i]) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}