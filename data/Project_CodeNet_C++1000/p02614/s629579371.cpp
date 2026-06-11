#include <iostream>
#include <vector>
using namespace std;

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h,vector<char>(w));
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) cin>>c[i][j];
    int ans=0;
    for(int i=0; i<(1<<h); i++){
        for(int j=0; j<(1<<w); j++){
            int cnt=0;
            for(int k=0; k<h; k++){
                for(int l=0; l<w; l++){
                    if(!(i&(1<<k))&&!(j&(1<<l))&&c[k][l]=='#'){
                        cnt++;
                    }
                }
            }
            if(cnt==k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}