#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=3.14159265358979323846;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

double dist(pair<double,double> a, pair<double,double> b) {
    double ax,ay,bx,by;
    tie(ax,ay)=a;
    tie(bx,by)=b;
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}


int main() {
    int n;
    cin>>n;
    vector<pair<double,double>> xy(n);
    rep(i,n) {
        double x,y;
        cin>>x>>y;
        xy[i]={x,y};
    }
    
    sort(all(xy), [](const auto &p1, const auto &p2) {
        return atan2l(p1.second, p1.first) < atan2l(p2.second, p2.first);
    });
    
    rep(i,n) xy.push_back(xy[i]);
    
    double ans=0;
    rep(left,n) {
        rep(right,n) {
            if(left>right) continue;
            {
                double x=0,y=0;
                FOR(i,left,right) {
                    x+=xy[i].first;
                    y+=xy[i].second;
                }
                ans=max(ans,dist({0,0},{x,y}));
            }
            {
                if(left==right) continue;
                double x=0,y=0;
                FOR(i,right,n-1) {
                    x+=xy[i].first;
                    y+=xy[i].second;
                }
                FOR(i,0,left) {
                    x+=xy[i].first;
                    y+=xy[i].second;
                }
                ans=max(ans,dist({0,0},{x,y}));
            }
        }
    }
    
    cout<<fixed<<setprecision(20)<<ans<<endl;
    
}
