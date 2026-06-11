#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int h,w,k;
char grid[10][10];

int solve(int a,int b){
    int cntb=0;
    for(int i = 0; i < h; i++){
        if(a&(1<<i)){
            continue;
        }
        for(int j = 0; j < w; j++){
            if(b&(1<<j)){
                continue;
            }
            cntb+=(grid[i][j]=='#');
        }
    }

    return cntb;
}



int main()
{
    cin >> h >> w >> k;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin>>grid[i][j];
        }
    }
    int cnt=0;
    for(int i = 0; i < (1<<h); i++){
        for(int j = 0; j < (1<<w); j++){
            if(solve(i,j)==k){
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}