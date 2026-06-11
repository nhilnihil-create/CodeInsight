#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> d(n);
    rep(i, n) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    ll right = d[n/2];
    ll left = d[n/2-1];
    cout << right - left << endl;

}