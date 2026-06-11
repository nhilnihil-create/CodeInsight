#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int h, w, k; cin>> h >> w >> k;
    vector<string> c(h);
    forin(c);

    int cnt = 0, ans = 0;
    for(int bit = 0; bit<(1<<h); bit++){
        for(int bit2 = 0; bit2<(1<<w); bit2++){
            for(int i = 0; i<h; i++)for(int j=0; j<w; j++){
                if(c[i][j] == '#' && !(bit & (1<<i)) && !(bit2 & (1<<j))) cnt++;
            }
            if(cnt == k) ans++;
            cnt = 0;
        }
    }
    cout<< ans << endl;
}
