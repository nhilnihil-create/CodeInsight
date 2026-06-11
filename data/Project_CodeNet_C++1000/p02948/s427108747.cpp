#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> jobs(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        jobs[i] = make_pair(a,b);
    }
    sort(jobs.begin(), jobs.end());
    reverse(jobs.begin(),jobs.end());

    priority_queue<int> pq;
    ll ans = 0;
    for(int i=1;i<=m;i++){
        while(jobs.size()>0 && jobs.back().first==i){
            pair<int,int> p = jobs.back();
            pq.push(p.second);
            jobs.pop_back();
        }
        if(!pq.empty()){ans += pq.top(); pq.pop();}
    }
    cout << ans << endl;
}