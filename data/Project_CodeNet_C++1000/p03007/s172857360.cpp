#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    int n;cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    int pc=0,mc=0;
    deque<int> P,M;
    rep(i,n){
        if(a[i]>=0){
            pc++;
            P.push_back(a[i]);
        }
        else{
            mc++;
            M.push_back(a[i]);
        }
    }
    if(pc==n){
        sort(a.rbegin(),a.rend());
        int mn=a[n-1];
        int mn2=mn;
        int mx=a[0];
        int mx2=mx;
        for(int i=1;i<n-1;i++){
            mn2-=a[i];
        }
        mx2-=mn2;
        cout << mx2 << endl;
        for(int i=1;i<n-1;i++){
            cout << mn << " " << a[i] << endl;
            mn-=a[i];
        }
        cout << mx << " " << mn << endl;
    }
    else if(pc==0){
        sort(a.rbegin(),a.rend());
        int mx=a[0]-a[n-1];
        for(int i=1;i<n-1;i++) mx-=a[i];
        cout << mx << endl;
        cout << a[0] << " " << a[n-1] << endl;
        int mx2=a[0]-a[n-1];
        for(int i=1;i<n-1;i++){
            cout << mx2 << " " << a[i] << endl;
            mx2-=a[i];
        }
    }
    else{
        int ans=0;
        deque<int> cP=P;
        deque<int> cM=M;
        while(cP.size()){
            ans+=cP.front();
            cP.pop_front();
        }
        while(cM.size()){
            ans-=cM.front();
            cM.pop_front();
        }
        cout << ans << endl;
        int sum=M.front();
        M.pop_front();
        mc--;
        while(pc>0&&mc>=0){
            if(pc==1){
                cout << P.front() << " " << sum << endl;
                sum=P.front()-sum;
                P.pop_front();
                pc--;
                while(mc>0){
                    cout << sum << " " << M.front() << endl;
                    sum-=M.front();
                    M.pop_front();
                    mc--;
                }
            }
            else{
                cout << sum << " " << P.front() << endl;
                sum-=P.front();
                P.pop_front();
                pc--;
            }
        }
    }
    return 0;
}