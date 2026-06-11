#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;


int main(){
    ll H, W;
    cin >> H >> W;

    vector<ll> R[H];
    vector<ll> C[W];
    string S[H];
    ll P[H][W];
    ll Rcount[H][W];
    ll Ccount[H][W];
    ll count;
    ll max = 0;

    for(ll i = 0; i < H; i++){
        cin >> S[i];
    }

    for(ll i = 0; i < H; i++){
        count = 0;
        for(ll j = 0; j < W; j++){
            if(S[i][j] == '.'){
                count++;
                if(j == W - 1){
                    R[i].push_back(count);
                    count = 0;
                }
            }else{
                R[i].push_back(count);
                count = 0;
            }
        }
    }
    for(ll i = 0; i < W; i++){
        count = 0;
        for(ll j = 0; j < H; j++){
            if(S[j][i] == '.'){
                count++;
                if(j == H - 1){
                    C[i].push_back(count);
                    count = 0;
                }
            }else{
                C[i].push_back(count);
                count = 0;
            }
        }
    }
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            if(j == 0){
                if(S[i][j] == '.'){
                    Rcount[i][j] = 0;
                }else{
                    Rcount[i][j] = 1;
                }
            }else{
                if(S[i][j] == '.'){
                    Rcount[i][j] = Rcount[i][j - 1];
                }else{
                    Rcount[i][j] = Rcount[i][j - 1] + 1;
                }
            }
        }
    }
    for(ll i = 0; i < W; i++){
        for(ll j = 0; j < H; j++){
            if(j == 0){
                if(S[j][i] == '.'){
                    Ccount[j][i] = 0;
                }else{
                    Ccount[j][i] = 1;
                }
            }else{
                if(S[j][i] == '.'){
                    Ccount[j][i] = Ccount[j - 1][i];
                }else{
                    Ccount[j][i] = Ccount[j - 1][i] + 1;
                }
            }
        }
    }

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            if(S[i][j] == '.' && max < R[i][Rcount[i][j]] + C[j][Ccount[i][j]] - 1){
                max = R[i][Rcount[i][j]] + C[j][Ccount[i][j]] - 1;
            }
        }
    }

    cout << max << endl;

    return 0;
}
