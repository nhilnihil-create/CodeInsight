#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int H,W,K;
    cin>>H>>W>>K;
    vector<vector<bool>> c(H,vector<bool>(W,0));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            char s;
            cin>>s;
            if(s=='#')c[i][j]=true;
        }
    }
    int ans=0;
    for (int h = 0; h < (1<<H); h++){
        bitset<6> bith(h);
        for (int w = 0; w < (1<<W); w++){
            bitset<6> bitw(w);
            int sum=0;
            for (int i = 0; i < H; i++){
                for (int j = 0; j < W; j++){
                    if(bith[i]==0&&bitw[j]==0&&c[i][j]==1)sum++;
                }
            }
            if(sum==K)ans++;
        }
    }
    cout<<ans<<endl;
}