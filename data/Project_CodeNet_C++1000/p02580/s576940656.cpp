#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 3*1e5+5;

set<pii> s;
int r[N], c[N];
vector<pii> R, L;

bool cmp(pii a, pii b){
    return a.fi > b.fi;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int h, w, m, a, b; cin >>h >>w >>m;
    for(int i = 0; i<m; i++){
        cin >>a >>b;
        r[a]++; c[b]++;
        s.insert({a, b});
    }

    for(int i = 1; i<=h; i++){
        R.push_back({r[i], i});
    }
    for(int i = 1; i<=w; i++){
        L.push_back({c[i], i});
    }

    sort(R.begin(), R.end(), cmp);
    sort(L.begin(), L.end(), cmp);

    int ans = R[0].fi + L[0].fi - s.count({R[0].se, L[0].se});
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(R[i].fi + L[j].fi > ans){
                ans = max(ans, R[i].fi + L[j].fi - (int) s.count({R[i].se, L[j].se}));
            }
            else break;
        }
    }

    cout <<ans <<endl;

    return 0;
}
