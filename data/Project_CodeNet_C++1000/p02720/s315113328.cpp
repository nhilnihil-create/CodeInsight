#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;

int main(void){
    ll k;
    cin>>k;
    queue<ll> q;
    vector<ll> v;
    for(ll i=1;i<=9;i++){
        q.push(i);
        v.push_back(i);
    }
    while(1){
        ll x=q.front();
        q.pop();
        ll y=x%10,z;
        if(y>=1){
            z=x*10+y-1;
            q.push(z);
            v.push_back(z);
        }
        z=x*10+y;
        q.push(z);
        v.push_back(z);
        if(y<=8){
            z=x*10+y+1;
            q.push(z);
            v.push_back(z);
        }
        if(v.size()>=100010) break;
    }
    cout<<v[k-1]<<endl;
}