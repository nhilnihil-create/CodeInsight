#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAX_R = 10;
const int MAX_C = 10000;

//input
int R, C;
bitset<MAX_C> a[MAX_R];

int ans;

void dfs(int k){
    if(k == R){
        //row certain
        int result = 0;            //cur max value
        for(int j = 0; j < C; j ++){
            int upNum = 0;            //up numbers without fliping
            for(int i = 0; i < R; i ++){
                if(a[i][j]) upNum ++;
            }
            result += max(upNum, R - upNum);    
        }
        ans = max(ans, result);
        return;
    }
    //without fliping
    dfs(k + 1);
    //&#183;flip
    a[k].flip();
    dfs(k + 1);

    a[k].flip();
}

void solve(){
    ans = 0;
    dfs(0);
    printf("%d\n", ans);
}

int main(int argc, char const *argv[]){

    while(scanf("%d %d", &R, &C)){
        if(R == 0 && C == 0) break;

        for(int i = 0; i < R; i ++){
            for(int j = 0; j < C; j ++){
                bool tmp;
                scanf("%d", &tmp);
                a[i][j] = tmp;
            }
        }
        solve();
    }

    return 0;
}