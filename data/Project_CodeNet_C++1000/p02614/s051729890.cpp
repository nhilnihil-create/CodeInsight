#include <iostream>
using namespace std;

#include <vector>
#include <string>
int main(){
    int h,w,k; cin >> h >> w >> k;
    vector<vector<int>> date(h,vector<int>(w));
    for(int i=0; i<h; i++){
        string str; cin >> str;
        for(int j=0; j<w; j++){
            if(str[j]=='.'){
                date[i][j] = 0;
            } else date[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i=0; i<(1<<h); i++){
        for(int j=0; j < (1<<w); j++){
            int total=0;
            for(int x=0; x<h; x++){
                if((i>>x)&1)continue;
                for(int y=0; y<w; y++){
                    if(!((j>>y)&1)) total += date[x][y];
                }
            }
            if(total==k)ans++;
        }
    }
    cout << ans << endl;
}