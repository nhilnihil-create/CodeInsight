#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int ans = 0;
    sort(l.begin(), l.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if((l[i] < l[j]+l[k]) && (l[j] < l[i]+l[k]) && (l[k] < l[i]+l[j])) ans++;
                else break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}