#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;
 
int main() {
    int H,W,M;
    cin >> H >> W >> M;

    vi h(M),w(M);
    map<int,int> hmp,wmp;
    set<P> st;
    rep(i,M){
        cin >> h[i] >> w[i];
        hmp[h[i]]++;
        wmp[w[i]]++;
        st.insert(P(h[i],w[i]));
    }

    int hmax = 0,wmax = 0;
    for(auto x : hmp) hmax = max(hmax,x.second);
    for(auto x : wmp) wmax = max(wmax,x.second);

    vi hh,ww;
    for(auto x : hmp) if(hmax == x.second) hh.push_back(x.first);
    for(auto x : wmp) if(wmax == x.second) ww.push_back(x.first);

    int add = 0;
    for(auto x : hh){
        for(auto y : ww){
            if(st.find(P(x,y))==st.end()){
                add = 1;
                break;
            }
        }
        if(add) break;
    }

    cout << hmax+wmax-1+add << endl;
 
	return 0;
}