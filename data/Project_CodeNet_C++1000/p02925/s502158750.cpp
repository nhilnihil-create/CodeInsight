#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

int aa(int a, int b){return min(a, b)*10000+max(a, b);}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    debug("debug test\n");
    int n,m;
    cin>>n;
    vvint a;
    initvv(a, n, n-1, 0);
    rep(i, n){
        rep(j, n-1){
            cin>>a[i][j];
        }
    }
    vint pos(n, 0);
    //vint t(n*(n+1)+n-1 + 1, 0);
    int day = 0;
    rep(i, min(n*(n-1)/2+1, 10000)){
        unordered_map<int, int> mm;
        rep(j, n){
            if(pos[j]>=n-1)continue;
            int aite = a[j][pos[j]];
            int v = mm[max(j+1, aite)*(n+1)+min(j+1, aite)];//mm[P(max(j+1, aite), min(j+1, aite))];
            //mm[P(max(j+1, aite), min(j+1, aite))]++;
            mm[max(j+1, aite)*(n+1)+min(j+1, aite)]++;
            //t[max(j+1, aite)*(n+1)+min(j+1, aite)]++;
        }
        bool flag = true, df = false;
        /*rep(j, n*(n+1)+n-1 + 1){
            if(t[j]==2){
                pos[j/(n+1)-1]++;
                pos[j%(n+1)-1]++;
                
                df = true;
                flag = false;
            }
            t[j] = 0;
        }*/
        for(auto i = mm.begin();i!=mm.end();i++){
            if(i->second==2){
                pos[(i->first)/(n+1)-1]++;
                pos[(i->first)%(n+1)-1]++;
                
                df = true;
                flag = false;
            }
        }
        //rep(k, n){
        //    debug("day(%d) pos %d : %d\n", day, k, pos[k]);
        //}
        if(df){day++;}
        if(flag){
            rep(k, n){
                if(pos[k]!=n-1){
                    cout << -1 << endl;
                    return 0;
                }
            }
            cout << day << endl;
            return 0;
        }
    }
    cout << n*(n-1)/2 << endl;
    return 0;
}
