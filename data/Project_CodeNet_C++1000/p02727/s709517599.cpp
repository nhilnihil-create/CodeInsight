#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll X ,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A,0);
    vector<ll> q(B,0);
    vector<ll> r(C,0);

    for(int i = 0; i < A; i++) cin >> p[i];
    for(int i = 0; i < B; i++) cin >> q[i];
    for(int i = 0; i < C; i++) cin >> r[i];

    sort(p.begin() ,p.end(),greater<ll>());
    sort(q.begin() ,q.end(),greater<ll>());
    sort(r.begin() ,r.end(),greater<ll>());
    for(int i = 0; i < A - X; i++) p.pop_back();
    for(int i = 0; i < B - Y; i++) q.pop_back();
    p.insert(p.end(),q.begin(),q.end());
    p.insert(p.end(),r.begin(),r.end());
    sort(p.begin() ,p.end(),greater<ll>());
    ll ans = 0;
    for(int i = 0; i < X + Y; i++) ans += p[i];

    cout << ans << endl;

}

