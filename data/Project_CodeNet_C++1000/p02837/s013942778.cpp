#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <math.h>                                                               
#include <stdio.h>   
using namespace std;
 
int main() {
    int n;cin>>n;
    int a[n][15];//嘘つき０正直１
    for(int i= 0;i<n;i++)for(int j=0;j<15;j++) a[i][j] = -1;
    for(int i = 0;i<n;i++){
      int aa;cin>>aa;
      for(int j = 0;j<aa;j++){
       int x,y;cin>>x>>y;
       if(y == 1) a[i][x-1]=1;
       else a[i][x-1] = 0;
      }
    }
    int saidai = 0;
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        int syo[n];
        for(int i= 0;i<n;i++) syo[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        for (int i = 0; i < (int)S.size(); ++i) {
            syo[S[i]] = 1;
        }
        int dame = 0;
        bool usotuki = false;
        for (int i = 0; i < (int)S.size(); ++i) {
          for(int j = 0;j < 15;j++){
               int b = a[S[i]][j];
               if(b == -1) continue;
               int dou = 0;
               if(b == 1) dou = 1;
               if(b == 0) dou = 0;
               if(dou != syo[j]){
                 usotuki = true;
                 break;
               }
           }
          if(usotuki){
            dame = 1;
            break;
          }
        }
        if(dame == 0) saidai = max((int)S.size(),saidai);
    }
    cout<<saidai;
    return 0;
}