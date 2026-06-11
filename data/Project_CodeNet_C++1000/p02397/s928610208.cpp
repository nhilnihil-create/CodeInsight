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
    int x,y;
    while(true){
        scanf("%d %d",&x,&y);
        if(x==y && x==0){
            break;
        }else if(x>y){
            printf("%d %d\n",y,x);
        }else{
            printf("%d %d\n",x,y);
        }
    }
    return 0;
}