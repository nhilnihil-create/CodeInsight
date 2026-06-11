#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h,w,m;
    cin >> h >> w >> m;
    vector<pair<int,int>> p;
    vector<int> cnth(h),cntw(w);
    set<pair<int,int>> st;
    int ans = 0;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        cnth[a]++;
        cntw[b]++;
        p.push_back({a,b});
        st.insert({a,b});
    }
    vector<pair<int,int>> wc;
    for(int i=0;i<w;i++){
        wc.push_back({cntw[i],i});
    }
    sort(wc.rbegin(),wc.rend());
    for(int i=0;i<h;i++){
        // ある行を決めた後にどの列を爆破するか決めるんだけど
        // 予め列ごとに個数を出しておく
        int tmp = cnth[i];
        int p = 0;
        while(wc[p+1].first == wc[p].first && p + 1 < w && st.count({i,wc[p].second})){
                p++;
        }
        tmp += wc[p].first;
        if(st.count({i,wc[p].second}))tmp--;
        chmax(ans,tmp);
    }
    cout << ans << endl;
}