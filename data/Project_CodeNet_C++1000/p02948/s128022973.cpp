#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m;cin>>n>>m;
    vector<int> a[100001];
    for (int i=0;i<n;i++) {
        int b,c;cin>>b>>c;
        a[b].push_back(c);
    }
    int ans=0;
    priority_queue<int> q;
    for (int i=1;i<=m;i++) {
        for (int x:a[i])
            q.push(x);
        if (q.size()) {
            ans+=q.top();q.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}