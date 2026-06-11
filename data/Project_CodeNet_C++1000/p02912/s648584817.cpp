#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    int n, m; cin>> n >> m;
    ll a;
    priority_queue<ll> pq;
    rep(i, n){
        cin>> a;
        pq.push(a);
    }
    rep(i, m){
        int tmp = pq.top();
        pq.pop();
        tmp /= 2;
        pq.push(tmp);
    }

    ll ans = 0;
    rep(i, n){
        int tmp = pq.top();
        pq.pop();
        ans += tmp;
    }
    cout<< ans << endl;
}
