#include<bits/stdc++.h>
using namespace std;
int road[20][20] = {0};
int main(){
    while(1){
        int W,H;
        cin >> W;
        cin >> H;
        if(W == 0 && H == 0){
            break;
        }
        int kp;
        cin  >> kp;
        vector<int>kpp[2];//0...x,1...y
        for(int i = 0;i < kp;i++){
            int x,y;
            cin >> x;
            cin >> y;
            kpp[0].push_back(x);
            kpp[1].push_back(y);
        }
        /*for(int i = 0;i < H;i++){
            for(int j = 0;j < W;j++){
                cout << road[i][j] << ' ';//3 0:2 1:1 2:0
            }
            cout << endl;
        }*/
        for(int i = 0;i < H;i++){
            for(int j = 0;j < W;j++){
                int f = 0;
                for(int k = 0;k < kp;k++){
                    if(i+1 == kpp[1][k] && j+1 == kpp[0][k]){
                        //cout << i+1 << ':' << j+1 << endl;
                        f = 1;
                        break;
                    }
                }
                if(i == 0 && j == 0){
                    road[i][j] = 1;
                }
                else if(i == 0 && f == 0){
                    road[i][j] = road[i][j-1];
                }
                else if(j == 0 && f == 0){
                    road[i][j] = road[i-1][j];
                }
                else if(f == 0){
                    road[i][j] = road[i-1][j]+road[i][j-1];
                }
            }
        }
        /*for(int i = 0;i < H;i++){
            for(int j = 0;j < W;j++){
                cout << road[H-1-i][j] << ' ';
            }
            cout << endl;
        }*/
        cout << road[H-1][W-1] << endl;
        for(int i = 0;i < 20;i++){
            for(int j = 0;j < 20;j++){
                road[i][j] = 0;
            }
        }
    }
    return 0;
}