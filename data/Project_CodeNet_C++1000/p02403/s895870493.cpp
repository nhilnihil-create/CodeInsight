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
    int h,w;
    for(;;){
        scanf("%d %d",&h,&w);
        if(h==0 && w==0) break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}