#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

static const int W = 5;
static const int H_MAX =  11;

int n;
int map[H_MAX][W];

int main(int argc, const char * argv[]) {
    // input from txt
    /////////
    //write//
    /////////
    
    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<W; j++){
                if(i==0)map[i][j] = -1;
                else cin >> map[i][j];
            }
        }
        
        bool erase_stone = true;
        int ans = 0;
        
        while(erase_stone){
            erase_stone = false;
            for(int i=1; i<n+1; i++){
                int cnt = 0;
                int now_stone = 0;
                for(int j=0; j<W; j++){
                    if(now_stone == -1 )cnt = 0;
                    if(!cnt){
                        now_stone = map[i][j];
                        cnt++;
                    }
                    else{
                        if(map[i][j] == now_stone){
                            cnt++;
                        }
                        else {
                            if(cnt>=3){
                                for(int itr=0; itr<cnt; itr++){
                                    ans += now_stone;
                                    for(int itr2 = i; itr2>0; itr2--){
                                        map[itr2][j-itr-1] = map[itr2-1][j-itr-1];
                                    }
                                    erase_stone = true;
                                }
                            }
                            cnt = 0;
                            now_stone = map[i][j];
                            cnt++;
                        }
                    }
                }
                if(cnt>=3){
                    for(int j=0; j<cnt; j++){
                        ans += now_stone;
                        for(int itr2 = i; itr2>0; itr2--){
                            map[itr2][W-j-1] = map[itr2-1][W-j-1];
                        }
                    }
                    erase_stone = true;
                }
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}


