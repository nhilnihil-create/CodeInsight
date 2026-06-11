#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7;

int n, m;
vector<int> v[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int t, c;
        cin >> t >> c;
        v[t].push_back(c);
    }
    priority_queue<int> pq;
    int ans = 0;
    for(int i = 1; i <= m; i++){
        while(v[i].size()){
            pq.push(v[i].back());
            v[i].pop_back();
        }
        if(pq.size()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;

    return 0;

}

