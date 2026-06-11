#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <stdio.h>

using namespace std;

vector<int> ball(10);

int dfs(int cnt, int l, int r){ 
    ++cnt;
    if(cnt == 10) return 1;
    if(ball[cnt] > r){ 
        if(dfs(cnt,l,ball[cnt])) return 1;
    }   
    else if(ball[cnt] > l){ 
        if(dfs(cnt,ball[cnt],r)) return 1;
    }   
    return 0;
}
int main(int argc, void *argv[]){
    int n;
    int tmp;
    
    scanf("%d", &n);
    while(n--){
        for(int i=0;i<10;i++){
            scanf("%d",&tmp);
            ball[i] = tmp;
        }   
        if(dfs(-1,0,0)) printf("YES\n"); else printf("NO\n");
    }   
}