#include<bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll = int64_t;

using namespace std;


int64_t n,m;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    using P = pair<ll,ll>;

    int64_t ans = 0;

    priority_queue<P> p;
    priority_queue<int64_t> q;

    REP(i,n){
        int64_t a,b;cin >> a >> b;
        p.emplace(-a,b);
    }

    for(int64_t i = 1;i <= m;i++){
        while(p.size()){
            if(-p.top().first <= i){
                q.push(p.top().second);
                p.pop();
            }else break;
        }
        if(q.size()){
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << '\n';
}

