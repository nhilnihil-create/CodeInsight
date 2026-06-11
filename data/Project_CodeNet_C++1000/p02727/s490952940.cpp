#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<long long int> p(a);
    for(int i=0; i<a; i++) cin >> p[i];
    vector<long long int> q(b);
    for(int i=0; i<b; i++) cin >> q[i];
    vector<long long int> r(c);
    for(int i=0; i<c; i++) cin >> r[i];

    sort(p.begin(), p.end()); reverse(p.begin(), p.end());
    sort(q.begin(), q.end()); reverse(q.begin(), q.end());
    sort(r.begin(), r.end()); reverse(r.begin(), r.end());

    priority_queue<long long int, vector<long long int>, greater<long long int>> apple;
    for(int i=0; i<x; i++) apple.push(p[i]);
    for(int i=0; i<y; i++) apple.push(q[i]);
    for(int i=0; i<c; i++){
        long long int least = apple.top();
        if(least < r[i]){
            apple.pop();
            apple.push(r[i]);
        }
    }

    long long int ans = 0;
    while(apple.empty() == false){
        long long int ap = apple.top(); apple.pop();
        ans += ap;
    }
    cout << ans << endl;
    return 0;
}