#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<LL> x(N);
    vector<LL> y(N);

    REP(i,N){
        cin >> x[i] >> y[i];
    }

    vector<LL> z(N);
    vector<LL> w(N);
    REP(i,N){
        z[i] = x[i] + y[i];
        w[i] = x[i] - y[i];
    }

    LL max_Z = *max_element(z.begin(), z.end());
    LL min_Z = *min_element(z.begin(), z.end());
    
    LL max_W = *max_element(w.begin(), w.end());
    LL min_W = *min_element(w.begin(), w.end());

    LL ans = max({max_Z-min_Z, max_W-min_W});

    cout << ans << endl;
    return 0;
}