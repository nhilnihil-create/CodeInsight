#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    multiset<int> mst;
    rep(i, n){
        int a; cin >> a;
        mst.insert(a);
    }
    vector<pii> res;
    while(mst.size()> 2){
        auto iter = mst.begin();iter++;
        int tmp = *iter, hasi;
        if(tmp >= 0){
            hasi = *mst.begin();
        }else{
            hasi = *mst.rbegin();
        }
        res.push_back({hasi, tmp});
        mst.erase(mst.find(hasi));
        mst.erase(mst.find(tmp));
        mst.insert(hasi - tmp);
    }

    int a = *mst.rbegin(), b = *mst.begin();
    res.push_back({a, b});
    cout << a-b << ln;
    for(auto p: res){
        cout << p.first << " " << p.second << ln;
    }
}
