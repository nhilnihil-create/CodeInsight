#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans;

    for(int i=1; i<=n; i++){
        auto result = find(a.begin(), a.end(), i);

        ans.push_back(distance(a.begin(), result)+1);
    }

    rep(i,n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}