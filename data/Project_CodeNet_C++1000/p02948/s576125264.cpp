#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<lli, lli> pi;


int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<lli>pq;
    vector<pi> v;
    for(int i=0; i<n; i++){
        lli a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int j=0;
    lli ans = 0;
    for(int i=1; i<=m; i++){
        while(j<n && v[j].first <= i){
            pq.push(v[j].second);
            j++;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}
