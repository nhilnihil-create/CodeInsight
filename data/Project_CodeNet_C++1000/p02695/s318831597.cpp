#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<int> a(Q), b(Q), c(Q), d(Q);
    rep(i,Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    rep(i,Q){
        a[i]--;
        b[i]--;
    }
    vector<vector<string> > vec(10, vector<string> (0));
    rep(i,M){
        vec[0].push_back(to_string(i));
    }
    rep(i,9){
        rep(j, vec[i].size()){
            int x = ctoi(vec[i][j][i]);
            for (int k = x; k < M; k++){
                vec[i + 1].push_back(vec[i][j] + to_string(k));
            }
        }
    }
    int ans = 0;
    rep(i,vec[N - 1].size()){
        string x = vec[N - 1][i];
        int subans = 0;
        rep(j,Q){
            if (ctoi(x[b[j]]) - ctoi(x[a[j]]) == c[j]) subans += d[j];
        }
        ans = max(ans, subans);
    }
    cout << ans << endl;
}