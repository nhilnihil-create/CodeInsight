#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
int main(){
    long long n, m, ans=0, i;
    map<long long, long long> mp;
    cin >> n >> m;
    dsu d(n);
    for(i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        a--;b--;
        d.merge(a, b);
    }
    for(i=0;i<n;i++){
        mp[d.leader(i)]++;
    }
    for(auto x : mp){
        ans++;
    }
    cout << ans-1 <<endl;
    return 0;
}