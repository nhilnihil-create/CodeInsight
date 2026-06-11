#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e8;

//---main---------------------------------------------
int main(){
    //main
    int H,W,M;
    cin >> H >> W >> M;

    //vector<vector<bool>> b(H, vector<bool>(W));
    vector<int> hb(H);
    vector<int> wb(W);
    //vector<P> b(M);
    set<P> b;


    int hi,wi;
    rep(mi,M){
        cin >> hi >> wi;
        hi--; wi--;
        hb[hi]++; wb[wi]++;
        //b[mi] = P(hi,wi);
        b.emplace(hi,wi);
        //b[hi][wi] = 1;
    }
    
    /*
    rep(hi,H){
        rep(wi,W){
            ans = max(ans, hb[hi]+wb[wi]-b[hi][wi]);
        }
    }
    */
    
    int hmax,wmax;
    hmax = *max_element(hb.begin(),hb.end());
    wmax = *max_element(wb.begin(),wb.end());

    vector<int> hl,wl;
    rep(hi,H) if(hb[hi]==hmax) hl.push_back(hi);
    rep(wi,W) if(wb[wi]==wmax) wl.push_back(wi);

    int ans = hmax + wmax;
    for(int hi : hl) for(int wi : wl){
        if( b.count(P(hi,wi)) )continue;
        cout << ans << endl;
        return 0;
    }
    cout << ans-1 << endl;


    /*
    rep(hi,H){
        if(hb[hi]==hmax){
            rep(wi,W){
                if(wb[wi]==wmax){
                    f = false;
                    rep(mi,M){
                        if(b[mi].first==hi && b[mi].second==wi){
                            f = true;
                            break;
                        }
                    }
                    if(!f){
                        cout << hmax+wmax << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << hmax+wmax-1 << endl;
    */


    /*
    vector<vector<int>> b(H, vector<int>(W));

    int hi,wi;
    rep(mi,M){
        cin >> hi >> wi;
        hi--; wi--;
        rep(i,H) b[i][wi]++;
        rep(i,W) b[hi][i]++;
        b[hi][wi]--;
    }
    int ans;
    vector<int> bh(H);
    rep(i,H) bh[i] = *max_element(b[i].begin(), b[i].end());

    cout << *max_element(bh.begin(), bh.end()) << endl;
    */


    return 0;
}