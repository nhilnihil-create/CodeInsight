#include<iostream>
#include <stdio.h>
#include<vector>
using namespace std;
int dfs(int n, int level){
    //printf("%d %d\n", n, level);
    if(n<0) return 0;
    if (level == 0 && n<0) return 0;
    if(level == 0 && n == 0) return 1;
    if(level > 0){
        int sum = 0;
        for(int i=0; i<=9; i++){
            if(i<=n)
                sum += dfs(n-i, level-1);
        }
        return sum;
    }
    return 0;
}
int main(){
    int n;
    while(scanf("%d\n", &n)!=EOF){
        printf("%d\n", dfs(n, 4));
    }
}