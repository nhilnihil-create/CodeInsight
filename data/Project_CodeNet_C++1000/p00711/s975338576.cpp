#include<stdio.h>
#include<iostream>
#include<list>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int ans;

void solve(char map[][22], int x, int y){
    ans++;
    map[x][y] = '#';
    if(map[x+1][y] == '.')
        solve(map, x+1, y);
    if(map[x][y+1] == '.')
        solve(map, x, y+1);
    if(map[x-1][y] == '.')
        solve(map, x-1, y);
    if(map[x][y-1] == '.')
        solve(map, x, y-1);
}

int main(){
    int width, height;
    while(cin >> width >> height, width||height){
        char map[22][22], str[22];
        rep(i,22)
            rep(j,22)
                map[i][j] = '#';
        int x, y;
        ans = 0;
        range(i, 1, height + 1){
            cin >> str;
            range(j, 1, width + 1){
                map[i][j] = str[j-1];
                if(map[i][j] == '@'){
                    x = i; y = j;
                }
            }
        }
        solve(map, x, y);
        cout << ans << endl;
    }
}