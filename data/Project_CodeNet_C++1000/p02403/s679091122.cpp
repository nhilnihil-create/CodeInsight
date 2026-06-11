#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>

typedef long long ll;

using namespace std;

void solve(){
    int h, w;
    while(cin >> h >> w){
        if(h == 0 && w == 0){
            return;
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}