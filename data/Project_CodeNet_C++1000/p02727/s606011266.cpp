#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a),q(b),r(c);
    for(ll i=0;i<a;i++)cin >> p[i];
    for(ll i=0;i<b;i++)cin >> q[i];
    for(ll i=0;i<c;i++)cin >> r[i];

    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());

    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());
    
    for(ll i=0;i<x;i++)r.push_back(p[i]);
    for(ll i=0;i<y;i++)r.push_back(q[i]);
    
    sort(r.begin(),r.end());
    reverse(r.begin(),r.end());

    ll s=0;
    for(ll i=0;i<x+y;i++)s+=r[i];

    //for(ll i=0;i<r.size();i++)cout << r[i] << endl;

    cout << s << endl;

}