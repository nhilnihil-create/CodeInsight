#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, M, ans=0, tmp=0;
//vector<pair<ll,ll>> job;
priority_queue<ll> job[100005];
priority_queue<pair<ll,ll>> PQ;
signed main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        ll a, b;
        cin >> a >> b;
        job[a].push(b);
    }
    for(int i=1;i<=M;i++) {
        //cout << "OK" << i << endl;
        if(!job[i].empty()) {
            PQ.push(make_pair(job[i].top(),i));
            job[i].pop();
        }
        //cout << "OK" << i << endl;
        pair<ll,ll> p;
        if(!PQ.empty()) {
            p = PQ.top();
            PQ.pop();
            ans += p.first;            
            if(!job[p.second].empty()) {
                PQ.push(make_pair(job[p.second].top(),p.second));
                job[p.second].pop();
            }
        }
        //cout << "OK" << i << endl;
    }
    cout << ans << endl;
    return 0;
}