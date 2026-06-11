#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N), C(N);
    rep(i,N){
        cin >> P[i];
        P[i]--;
    }
    rep(i,N){
        cin >> C[i];
    }
    ll ans = -1e18;
    /*rep(i,N){
        ll cur = i;
        ll sum = 0;
        vector<ll> s;
        while(1){
            cur = P[cur];
            s.push_back(C[cur]);
            sum += C[cur];
            if(cur == i) break;
        }
        ll l = s.size();
        ll t = 0;
        rep(j,l){
            t += s[j];
            if(j+1 > K) break;
            ll now = t;
            if(sum > 0){
                ll e = (K-(j+1))/l;
                now += sum*e;
            }
            cmax(ans, now);
        }
    }
    cout << ans << endl;*/
    
    rep(i,N){
        ll cur = i; 
        ll cnt = 0;
        //ll sum = 0;
        ll sum = 0;//C[P[cur]];
        vector<ll> memo(N);
        //vector<ll> S(N+10);
        //memo[P[cur]] = 1;
        //S[cnt] = sum;
        //cmax(ans,sum);
        //cnt++;
        //cur = P[cur];
        rep(j,min(N,K)){
            if(memo[P[cur]] != 0){
                break;
            }
            sum += C[P[cur]];
            cnt++;
            //S[cnt] = sum;
            memo[P[cur]] = 1;
            cur = P[cur];
            cmax(ans,sum);//ここの行のコメントはずすとWAになる。→なぜ？
        }
        /*
        if(N >= K){
            continue;
        }
        /*
        while(1){
            if(memo[cur] > 0){
                break;
            }
            memo[cur] = 1;
            sum += C[cur];
            //memo[P[cur]] = cnt;
            cur = P[cur];
            cnt++;
        }*/
        //cmax(ans, sum);
        //if(K <= N) continue;
        //cnt = memo[cur] - memo[P[cur]] + 1;
        //sum = S[memo[cur]];
        /*ll t = 0;
        cur = P[i];
        rep(j,cnt){
            t += C[cur];
            if(j+1 > K)break;
            ll now = t;
            if(sum > 0){
                ll e = (K-(j+1))/cnt;
                now += sum*e;
            }
            cur = P[cur];
            cmax(ans,now);
        }*/
        /*
        if(sum <= 0) continue;
        */
        ll q = ll(K/cnt) - 1;
        ll r = K%cnt;
        if(q < 0){
            cnt = 0;
            sum = 0;
            cur = i;
        }else{
            if(sum > 0){
                sum = sum*q;
            }else{
                sum = 0;
            }
            cur = i;
        }
        rep(j, cnt+r){
            sum += C[P[cur]];
            cur = P[cur];
            cmax(ans, sum);
        }        
        cmax(ans, sum);
    }
    cout << ans << endl;
}