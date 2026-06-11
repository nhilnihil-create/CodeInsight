#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a);
    for(int i=0;i<a;i++) cin >> p[i];
    vector<int> q(b);
    for(int i=0;i<b;i++) cin >> q[i];
    vector<int> r(c);
    for(int i=0;i<c;i++) cin >> r[i];
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    sort(r.begin(),r.end());
    reverse(r.begin(),r.end());
    
    ll sum=0;
    vector<int> s;
    for(int i = a-x; i < a; i++) {
        sum += p[i];
        s.push_back(p[i]);
    }
    for(int i = b-y; i < b; i++) {
        sum += q[i];
        s.push_back(q[i]);
    }
    sort(s.begin(),s.end());
    
    int i=0;

    while(i<c && i<x+y){
        sum += max(s[i],r[i])-s[i];
        i++;
    }
    cout << sum << endl;
    return 0;
}