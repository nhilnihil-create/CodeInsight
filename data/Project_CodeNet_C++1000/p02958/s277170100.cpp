#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, N) cin >> p[i];
    int cnt = 0;
    for(int i=1; i<=N; ++i){
        if(i!=p[i-1]) cnt++;
    }
    cout << (cnt==2||cnt==0 ? "YES": "NO") << endl;
    return 0;
}
