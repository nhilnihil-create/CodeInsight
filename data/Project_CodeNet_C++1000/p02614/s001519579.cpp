#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);

    for(int i = 0; i < h; i++){
        cin >> c[i];
    }

    int ans = 0;
    for(int bith = 0; bith < (1 << h); bith++){
        for(int bitw = 0; bitw < (1 << w); bitw++){

            int cntb = 0;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(c[i][j] == '#'){
                        if(((bith >> i) & 1) == 0 && ((bitw >> j) & 1) == 0){
                            cntb++;
                        }
                    }
                }
            }
            if(cntb == k) ans++;

        }
    }
    cout << ans << endl;
    return 0;
}