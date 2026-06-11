#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    int n; cin >> n;
    vector<int> l(n);
    rep(i,n){
        cin >> l[i];
    }
    sort(l.begin(),l.end());

    ll res = 0;
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            auto it = lower_bound(l.begin(),l.end(),l[i]+l[j]);
            ll ng = distance(it, l.end());
            res += (n-1-i)-ng;
        }
    }
    cout << res << endl;
}