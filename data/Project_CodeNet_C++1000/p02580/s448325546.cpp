#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }


int main(){
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> hcount(h), wcount(w);
    set<P> s;
    rep(i,m){
        int hi, wi;
        cin >> hi >> wi;
        hi--; wi--;
        hcount[hi]++; wcount[wi]++;
        s.insert(P(hi,wi));
    }
    int hmax = *max_element(hcount.begin(),hcount.end());
    int wmax = *max_element(wcount.begin(),wcount.end());
    int ans = hmax + wmax;
    vector<int> x, y;
    rep(i,h){
        if(hcount[i]==hmax) y.push_back(i);
    }
    rep(i,w){
        if(wcount[i]==wmax) x.push_back(i);
    }
    for(int i : y){
        for(int j : x){
            if(s.count(P(i,j))) continue;
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans - 1 << endl;

    return 0;
}