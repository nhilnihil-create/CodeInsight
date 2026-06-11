#include <bits/stdc++.h>
#define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
#define rep(i,n) drep(i,0,(n)-1)
#define drrep(i,cc,n) for(int i=(cc);i>=(n);--i)
#define rrep(i,n) drrep(i,0,(n)-1)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,v.size())if(i==0)cout << v[i];else cout << " " << v[i]; cout << endl;
#define arrprint(v,n) rep(i,n)if(i==0)cout << v[i];else cout << " " << v[i]; cout << endl;
#define matprint(v,n,m) rep(i,n){rep(j,m){cout << v[i][j] << " ";}cout << endl;}
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
using namespace std;
const int mod=1000000007;
const long long INF=-1001001001001;
using ll = long long;
using P = pair<int,int>;
template<typename T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>; //小さいものから取り出す


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> p(n),c(n);
    rep(i,n){cin >> p[i];p[i]--;}
    rep(i,n)cin >> c[i];
    vector<int> a[5000];
    set<int> s;
    int con = 0;
    rep(i,n){
        int now = i;
        if(s.find(now) != s.end())continue;
        a[con].push_back(now);
        s.insert(now);
        while(p[now] != a[con][0]){
            now = p[now];
            a[con].push_back(now);
            s.insert(now);
        }
        con++;
    }
    ll ans = INF;
    rep(i,con){
        ll tans = 0;
        int l = sz(a[i]);
        ll all = 0;
        rep(j,l) all += c[a[i][j]];
        int kk;
        if(all>0){
            if(k/l > 1){
                tans = all*(k/l-1);
                kk  = k%l+l;
            }else{
                kk = k;
            }
        }else{
            kk = min(k,l);
        }
        ll ttans = INF;
        rep(j1,l){
            ll tans2 = 0;
            rep(jj,kk){
                int j2 = (j1+jj)%l;
                tans2 += c[a[i][j2]];
                ttans = max(ttans,tans2);
                // if(i == 1)cout << jj << " " << tans2 << endl;;
            }
        }
        tans += ttans;
        // cout << i << " " << l << " " << tans << " " << kk << " " << all << endl;
        ans = max(ans,tans);
    }
    // cout << con << endl;

    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}