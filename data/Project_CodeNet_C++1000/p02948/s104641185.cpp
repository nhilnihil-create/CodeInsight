#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;



int main(){
    int n, m; cin >> n >> m;
    vi a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    vii award(m);
    for(int i=0; i<n; i++){
        if(a[i] > m) continue;
        award[m-a[i]].push_back(b[i]);
    }
    priority_queue<int, vi, less<int>> pque;
    ll ans=0;
    for(int i=m-1; i>=0; i--){
        for(auto x: award[i]) pque.push(x);
        if(pque.empty()) continue;
        ans+=pque.top();
        pque.pop();
    }
    cout << ans << endl;
    return 0;
}