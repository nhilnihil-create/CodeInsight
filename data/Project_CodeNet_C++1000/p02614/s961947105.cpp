#include<bits/stdc++.h>
using namespace std;

int main(){
    int h , w , k; cin >> h >> w >> k;
    vector<string> c(h);
    for(int i=0; i<h; i++) cin >> c[i];

    //answer
    int ans = 0;

    for(int i=0; i<(1<<h); i++){
        for(int j=0; j<(1<<w); j++){
            int cnt = 0; // the nuber of black
            for(int m=0; m<h; m++){
                if(i & (1<<m)) continue;
                for(int n=0; n<w; n++){
                    if(j & (1<<n)) continue;
                    if(c[m][n] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }

    cout << ans << endl;
}