#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long,long long>;

int main(){
    int N; cin >> N;
    vector<pll> v(N);
    for(int i = 0; i < N; i++){
        long long a,l;
        cin >> a >> l;
        v[i] = {a-l,a+l};
    }
    
    sort(v.begin(),v.end(),[](pll a,pll b){
        return a.second < b.second;
    });
    
    int res = 0;
    long long cur = -(1LL << 60);
    for(int i = 0; i < N; i++){
        if(cur > v[i].first) continue;
        ++res;
        cur = v[i].second;
    }
    cout << res << endl;

}
