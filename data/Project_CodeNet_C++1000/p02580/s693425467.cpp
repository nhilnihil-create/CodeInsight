#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_aru(vector<int> a, int num){
    rep(i, a.size()){
        if(a[i]==num) return true;
    }
    return false;
}

int main(){
    int H, W, M; cin >> H >> W >> M;
    int h[M], w[M];
    rep(i, M) cin >> h[i] >> w[i];

    int max_h=0, max_w=0;
    int num_h[H]={0}, num_w[W]={0};
    set<P> s;
    rep(i, M){
        s.emplace(h[i]-1, w[i]-1);
        num_h[h[i]-1]++;
        if(num_h[h[i]-1] > max_h) max_h=num_h[h[i]-1];
        num_w[w[i]-1]++;
        if(num_w[w[i]-1] > max_w) max_w=num_w[w[i]-1];
    }

    vector<int> h_l_num;
    vector<int> w_l_num;

    rep(i, H){
        if(num_h[i]==max_h) h_l_num.push_back(i);
    }
    rep(i, W){
        if(num_w[i]==max_w) w_l_num.push_back(i);
    }

    int ans=max_h+max_w;
    int numnum=0;
    // rep(i, M){
    // rep(i, h_l_num.size()) cout<<h_l_num[i]+1<<" ";
    // cout<<endl;
    // rep(i, w_l_num.size()) cout<<w_l_num[i]+1<<" ";
    // cout<<endl;
    rep(i, int(h_l_num.size())){
        rep(j, int(w_l_num.size())){
            if(s.count(P(h_l_num[i], w_l_num[j]))) continue;
            cout<<ans<<endl;
            return 0;
        }
    }

        // if(is_aru(h_l_num, h[i]-1)){
        //     if(is_aru(w_l_num, w[i]-1)){
        //         numnum++;
        //     }
        // }
    // }

    // int a=h_l_num.size(), b=w_l_num.size();
    // if(numnum>=a*b) ans=max_h+max_w-1;
    // else ans=max_h+max_w;

    cout << ans-1 << endl;

    return 0;
}