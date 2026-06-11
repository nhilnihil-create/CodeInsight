#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
signed main(){
    int N; cin >> N;
    vector<int>v(N);
    for(auto & e : v) cin >> e;
    sort(v.begin(),v.end());
    vector<pii>ans;
    int bound = N - 1;
    for(int i = 0; i < N; ++i){
        if(v[i] >= 0){
            bound = i; break;
        }
    }
    if(bound == 0) bound = 1;
    // bound is minimum unsigned integer
    for(int i = N - 2; i >= bound; --i){
        if(bound - 1 >= 0){
            ans.emplace_back(v[bound - 1] , v[i]);
            v[bound - 1] -= v[i];
        }
    }
    for(int i= 0; i < bound; ++i){
        ans.emplace_back(v.back(),v[i]);
        v.back() -= v[i];
    }
    cout << v.back() << endl;
    for(auto p : ans)
        cout << p.first << " " << p.second << endl;
}
