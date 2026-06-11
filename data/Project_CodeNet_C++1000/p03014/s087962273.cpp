#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int H, W;
    cin >> H >> W;
    vector<char> s(H*W);
    for(int i = 0; i < H*W; i++) cin >> s.at(i);
    
    vector<int> yoko(H*W, 0);
    vector<int> tate(H*W, 0);
    int answer = 0;
    int tmp;
    for (int h = 0; h < H; h++) {
        tmp = 0;
        for (int w = 0; w < W; w++) {
            if(s[w+W*h] == '.'){
                tmp++;
                yoko[w+W*h] = tmp;
            }
            else{
                tmp = 0;
            }
        }
        tmp = 0;
        for (int w = W-1; w >= 0; w--) {
            if(tmp == 0){
                tmp = yoko[w+W*h];
            }
            if(yoko[w+W*h] >= 1){
                yoko[w+W*h] = tmp;
            }
            else{
                tmp = 0;
            }
        }
    }

    for (int w = 0; w < W; w++) {
        tmp = 0;
        for (int h = 0; h < H; h++) {
            if(s[w+W*h] == '.'){
                tmp++;
                tate[w+W*h] = tmp;
            }
            else{
                tmp = 0;
            }
        }
        tmp = 0;
        for (int h = H-1; h >= 0; h--) {
            if(tmp == 0){
                tmp = tate[w+W*h];
            }
            if(tate[w+W*h] >= 1){
                tate[w+W*h] = tmp;
            }
            else{
                tmp = 0;
            }
        }
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            answer = max(answer, yoko[w+W*h] + tate[w+W*h] -1);
        }
    }
    printf("%d\n", answer);

}
