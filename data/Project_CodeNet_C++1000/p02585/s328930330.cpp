#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define ALL(obj) (obj).begin(), (obj).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};


int main() {
    cout<<fixed<<setprecision(10);

    ll n,k; cin>>n>>k;
    vint p(n); rep(i,n) {cin>>p[i]; p[i]--;}
    vint c(n); rep(i,n) cin>>c[i];

    ll ans = LLONG_MIN;

    auto eval = [&](ll st){
        // cout<<st<<endl;
        vint score(n, 0);
        vint num(n,0);
        vector<bool> visited(n, false);
        // visited[st] = true;
        ll now = st;
        ll nxt = p[now];
        ll cnt = 0;
        ll ret = c[nxt];

        while(!visited[nxt]){
            cnt++;
            // cout<<"cnt: "<<cnt<<endl;
            // cout<<"(now, nxt) = "<<now<<" "<<nxt<<endl;
            score[nxt] = score[now] + c[nxt];
            visited[nxt] = true;
            num[nxt] = cnt;
            chmax(ret, score[nxt]);
            now = nxt;
            nxt = p[nxt];
            if(cnt == k) return ret;
        }

        // for(auto e:score)cout<<e<<" "; cout<<endl;

        ll diff = score[now] - score[nxt] + c[nxt];
        // cout<<"diff: "<<diff<<endl;

        ll res = k - cnt;

        if(diff <= 0){
            ll tmp = score[now];
            chmin(res, n);
            while(res>0){
                res--;
                tmp += c[nxt];
                nxt = p[nxt];
                chmax(ret, tmp);
            }
            return ret;
        }

        ll T = num[now] - num[nxt] + 1; // 周期
        ll loop = max(res/T - 2, 0ll); // loop回数
        // ret += diff*loop;
        res -= T*loop;

        // cout<<res<<" "<<loop<<endl;

        ll tmp = score[now] + diff*loop;

        while(res>0){
            res--;
            tmp += c[nxt];
            now = nxt;
            nxt = p[nxt];
            chmax(ret, tmp);
        }

        return ret;

    };

    rep(st, n){
        chmax(ans, eval(st));
    }



    cout<<ans<<endl;

    return 0;

}