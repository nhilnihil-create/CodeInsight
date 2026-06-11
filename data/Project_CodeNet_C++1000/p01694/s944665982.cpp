#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? 1e9:1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vectors<decltype(inner)>(x, inner); }
template<class T> void show_with_brank(T a){ int cnt = 0; for(auto itr :a){ if(cnt++ != 0) cout << " "; cout << itr;} }
using ll  = long long;
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
#define int ll
signed main(){
    int n;
    while(cin >> n,n){
        int ans  = 0;
        vector<string>vs(n);
        rep(i,n){
            cin >> vs[i];
        }
        reverse(all(vs));
        int now = 0;
        rep(i,n/2){
            string a,b;
            a = vs.back();
            vs.pop_back();
            b = vs.back();
            vs.pop_back();
            if(a > b) swap(a, b);
            if(now == 0  && (a == "lu" && b == "ru")){ans++;now ++;}
            else if(now == 1  && (a == "ld" && b == "rd")){ans++;now--;};
        }
        cout << ans << endl;
    }
}




