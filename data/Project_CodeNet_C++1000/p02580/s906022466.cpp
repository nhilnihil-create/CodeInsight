#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl

int main() {
    ll H, W, m;
    cin >> H >> W >> m;

    vector<ll> h(m), hcnt(H, 0);
    vector<ll> w(m), wcnt(W, 0);
    for(int i = 0; i < m; i++){
        cin >> h[i] >> w[i];
        h[i]--; w[i]--;
        hcnt[h[i]]++; wcnt[w[i]]++;
    }
    ll hmax = 0;
    ll wmax = 0;
    for(int i = 0; i < H; i++){
        hmax = max(hmax, hcnt[i]);
    }
    for(int i = 0; i < W; i++){
        wmax = max(wmax, wcnt[i]);
    }
    vector<ll> hmax_index;
    vector<ll> wmax_index;
    for(int i = 0; i < H; i++){
        if(hmax == hcnt[i]){hmax_index.push_back(i);}
    }
    for(int i = 0; i < W; i++){
        if(wmax == wcnt[i]){wmax_index.push_back(i);}
    }
    ll hcandidate_num = hmax_index.size();
    ll wcandidate_num = wmax_index.size();

    if(hcandidate_num * wcandidate_num > m){
        cout << hmax + wmax << endl;
    }else{
        set<pll> st;
        for(int i = 0; i < m; i++){
            st.insert({h[i],w[i]});
        }
        bool is_cross = true;
        for(auto eh: hmax_index){
            for(auto ew: wmax_index){
                if(st.find({eh, ew}) == st.end()){
                    is_cross = false;
                }
            }
        }
        if(is_cross){
            cout << hmax + wmax - 1 << endl;
        }else{
            cout << hmax + wmax << endl;
        }
    }



    return 0;
}
