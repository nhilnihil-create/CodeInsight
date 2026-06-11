#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    vector<ll> b(n, 0);

    vector<pair<ll, ll>> diff;

    REP(i, n) {
        cin >> a[i] >> b[i];
        diff.push_back(make_pair(b[i], a[i]));
    }

    sort(ALL(diff));


    ll time = 0;

    REP(i, n){
        if (time+diff[i].second > diff[i].first){
            cout << "No" << endl;
            return 0;
        }
        time += diff[i].second;
    }
    
    cout << "Yes" << endl;
    return 0;
}