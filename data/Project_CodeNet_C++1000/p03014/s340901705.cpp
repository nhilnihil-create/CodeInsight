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

int h;
int w;
char f[2005][2005];
int d[2005][2005];
int u[2005][2005];
int r[2005][2005];
int l[2005][2005];

int main()
{
    cin >> h >> w;
    for (int i = 0;i < h;i++){
        for (int j = 0;j < w;j++){
            cin >> f[i][j];
        }
    }
    
    for (int i = 0;i < w;i++){
        if (f[h-1][i] == '.'){
            d[h-1][i] = 1;
        }
        else {
            d[h-1][i] = 0;
        }
        
        if (f[0][i] == '.'){
            u[0][i] = 1;
        }
        else {
            u[0][i] = 0;
        }
    }
    
    for (int j = 0;j < h;j++){
        if (f[j][0] == '.'){
            l[j][0] = 1;
        }
        else {
            l[j][0] = 0;
        }
        
        if (f[j][w-1] == '.'){
            r[j][w-1] = 1;
        }
        else {
            r[j][w-1] = 0;
        }
    }
    
    for (int i = 0;i < h;i++){
        for (int j = 0;j < w;j++){
            if (f[i][j] == '.' && j >= 1){
                l[i][j] = l[i][j-1] + 1;
            }
            
            if (f[i][w-j-1] == '.' && j >= 1){
                r[i][w-j-1] = r[i][w-j] + 1;
            }
            
            if (f[i][j] == '#'){
                l[i][j] = 0;
                u[i][j] = 0;
                r[i][j] = 0;
                d[i][j] = 0;
            }
            
            if (f[i][j] == '.' && i >= 1){
                u[i][j] = u[i-1][j] + 1;
            }
            
            if (f[h-i-1][j] == '.' && i >= 1){
                d[h-i-1][j] = d[h-i][j] + 1;            }
        }
    }
    
    int ans = 0;
    for (int i = 0;i < h;i++){
        for (int j = 0;j < w;j++){
            ans = max(l[i][j] + r[i][j] + d[i][j] + u[i][j]-3,ans);
        }
    }
    
    cout << ans << endl;
}
