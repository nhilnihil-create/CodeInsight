#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int H,W,K;
    cin >> H >> W >> K;
    vector<string> A(H);
    for (int i = 0; i < A.size(); i++){
        cin >> A[i];
    }
    int ans=0;
    for (int i = 0; i < 1<<H; i++){
        for (int j = 0; j < 1<<W; j++){
            int c=0;
            for (int k = 0; k < H; k++){
                if (((i>>k)&1)==0){
                    continue;
                }
                for (int l = 0; l < W; l++){
                    if(((j>>l)&1)==0){
                        continue;
                    }
                    if (A[k].at(l)=='#'){
                        c++;
                    }
                }
            }
            if(c==K){
                ans++;
            }
        }
    }
    cout << ans << endl;
}