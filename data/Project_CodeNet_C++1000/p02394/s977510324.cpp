#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * vector<int>ar(3);
 * for(auto&e:ar){
 *     scanf("%d",&e);
 * }
 * sort(ar.begin(),ar.end())
 * int sum=accumulate(ar.begin(),ar.end(),0);
 ***/

int main(){
    double pai=3.141592653589;
    int W,H,x,y,r;
    scanf("%d %d %d %d %d",&W,&H,&x,&y,&r);
    if(x-r>=0 && x+r<=W && y-r>=0 && y+r<=H){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}