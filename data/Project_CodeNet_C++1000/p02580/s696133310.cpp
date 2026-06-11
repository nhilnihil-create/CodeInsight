#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using pint = pair<int,int>;

tuple<vector<int>,int> maxpos( vector<int> x ){
    vector<int> ans;
    int xmax = 0;
    REP(i,x.size()){
        xmax = max(xmax,x[i]);
    }
    //cout << "max" << xmax << endl;
    REP(i,x.size()){
        if ( xmax == x[i] ) ans.push_back(i);
    }
    return forward_as_tuple(ans,xmax);
}

int main() {
    int H,W,M;
    cin >> H >> W >> M;
    vector<int> h(M),w(M);
    vector<int> x(H,0),y(W,0);
    set<pint> st;
    REP(i,M) {
        int a,b;
        cin >> a >> b; --a; --b;
        h[i] = a; w[i] = b;
        x[h[i]] += 1;
        y[w[i]] += 1;
        st.insert(pint(h[i],w[i]));
    }
    
    vector<int> xmax,ymax;
    int xl,yl;
    tie(xmax,xl) = maxpos(x); tie(ymax,yl) = maxpos(y);
    
    
    
    int ans = xl + yl - 1;
    for ( auto xx: xmax ) {
        for ( auto yy: ymax ){
            if ( st.find(pint(xx,yy)) == st.end() ){
                ++ans;
                goto OUT;
            }
        }
    }
    OUT:
    cout << ans << endl;
    
    return 0;
}

/*
 3 3 3
 1 1
 2 2
 3 3
 -> ans = 2
 */
