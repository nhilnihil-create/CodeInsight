#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
    int H,W,K;
    char c[7][7];
    
    cin >> H >> W >> K;
    for (int i = 0;i < H;i++){
        for (int j = 0;j < W;j++){
            cin >> c[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0;i < (1<<H);i++){
        for (int j = 0;j < (1<<W);j++){
            int res = 0;
            for (int k = 0;k < H;k++){
                for (int l = 0;l < W;l++){
                    if (((i>>k)%2) && ((j>>l)%2) && c[k][l] == '#'){
                        res++;
                    }
                }
            }
            if (res == K){
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}
