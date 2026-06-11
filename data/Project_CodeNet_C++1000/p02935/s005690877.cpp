#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    priority_queue<ld, vector<ld>, greater<ld> > pq;
    vector<ld> v(n);
    for(int i  = 0; i < n; ++i){
        ld x; cin >> x;
        pq.push(x);
    }
    ld ans = 0;    
    while(pq.size() > 1){
        ld f = pq.top();
        pq.pop();
        ld s = pq.top();
        pq.pop();
        pq.push((f + s)/2);
    }
    cout << fixed << setprecision(9);
    cout << pq.top() << '\n';
    return 0;
}