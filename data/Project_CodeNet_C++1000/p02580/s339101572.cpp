#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

int kamr[N], kamc[N];
set<int> vr[N], vc[N];
vector<int> v;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    int mxr = 0, mxc = 0;
    while(x--){
        int r, c;
        cin >> r >> c;
        kamr[r]++;
        mxr = max(mxr, kamr[r]);
        kamc[c]++;
        mxc = max(mxc, kamc[c]);
        vr[r].insert(c);
        vc[c].insert(r);
    }
    for(int i = 1; i <= m; i++){
        if(kamc[i] == mxc){
            v.push_back(i);
        }
    }
    int ans = mxr + mxc - 1;
    bool found = 0;
    for(int i = 1; i <= n && !found; i++){
        if(kamr[i] == mxr){
            for(auto j: v){
                if(vr[i].find(j) == vr[i].end() || vc[j].find(i) == vc[j].end()){
                    found = 1;
                    break;
                }
            }
        }
    }
    cout << ans + found;


    return 0;
}
