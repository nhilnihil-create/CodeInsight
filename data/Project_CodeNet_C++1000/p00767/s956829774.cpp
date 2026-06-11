#include<bits/stdc++.h>
using namespace std;

int main(void){

    while(1){
        int h, w; cin >> h >> w;
        if(h == 0) break;
        bool flag = 0;

        int ans_i = 200, ans_j = 200;
        int temp = 2000000000;
        for(int i = h + 1; i < 200; i++){
            for(int j = i + 1; j < 200; j++){
                if(h*h + w*w == i*i + j*j){
                    if(i == h && j == w) continue;
                    flag = 1;
                    ans_i = i;
                    ans_j = j;
                    break;
                }
            }
            if(flag == 1) break;
        }

        if(flag == 1){
            cout << ans_i << " " << ans_j << endl;
            continue;
        }else{
            for(int i = 1; i < 200; i++){
                for(int j = i + 1; j < 200; j++){
                    if(temp > i*i + j*j && h*h + w*w < i*i + j*j){
                        ans_i = i;
                        ans_j = j;
                        temp = i*i + j*j;
                    }
                }
            }

            cout << ans_i << " " << ans_j << endl;
        }

    }



    return 0;
}