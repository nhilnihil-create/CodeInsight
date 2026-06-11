#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#define ll long long
#define INF 100000000000
#define N 10000000
using namespace std;

int main(){
    int h,w,k;
    cin>>h>>w>>k;
    char data[h][w];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>data[i][j];
        }
    }
    
    int ans=0;
    
    for(int bit=0; bit<(1<<h); bit++){
        vector<int> S;
        for(int i=0; i<h; i++){
            if(bit & (1<<i)) S.push_back(1);
            else S.push_back(0);
        }
        for(int bit2=0; bit2<(1<<w); bit2++){
            vector<int> T;
            for(int i=0; i<w; i++){
                if(bit2 & (1<<i)) T.push_back(1);
                else T.push_back(0);
            }
            
            char num[h][w];
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    num[i][j]=data[i][j];
                }
            }
            
            for(int i=0; i<h; i++){
                if(S[i]==1){
                    for(int a=0; a<w; a++) num[i][a]='?';
                }
                for(int j=0; j<w; j++){
                    if(T[j]==1){
                        for(int b=0; b<h; b++) num[b][j]='?';
                    }
                }
            }
            
            int count=0;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(num[i][j]=='#') count++;
                }
            }
            
            if(count==k) ans++;
        }
    }
    
    cout<<ans<<endl;
}