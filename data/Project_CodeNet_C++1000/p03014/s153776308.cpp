#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    char m[h][w];
    int che[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> m[i][j];
            che[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(m[i][j] == '.'){
                int cou = 1;
                for(int k = 1; i + k < h; k++){
                    if(m[i + k][j] == '.'){
                        cou++;
                    }else{
                        break;
                    }
                }

                for(int k = 1; i - k >= 0; k++){
                    if(m[i - k][j] == '.'){
                        cou++;
                    }else{
                        break;
                    }
                }

                for(int k = 1; j + k < w; k++){
                    if(m[i][j + k] == '.'){
                        cou++;
                    }else{
                        break;
                    }
                }

                for(int k = 1; j - k >= 0; k++){
                    if(m[i][j - k] == '.'){
                        cou++;
                    }else{
                        break;
                    }
                }

                if(ans < cou){
                    ans = cou;
                }
            }

            if(ans == h + w - 1){
                break;
            }
        }

        if(ans == h + w - 1){
            break;
        }
    }

    cout << ans << endl;
}