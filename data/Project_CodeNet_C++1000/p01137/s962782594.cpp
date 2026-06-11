#include<cstdio>

int solve(int e){
    int res=e;
    for(int z=0;z*z*z<=e;z++){
        for(int y=0;y*y+z*z*z<=e;y++){
            if(res>e+y+z-y*y-z*z*z) res=e+y+z-y*y-z*z*z;
        }
    }
    return res;
}

int main(){
    while(1){
        int e;
        scanf("%d",&e);
        if(e==0) return 0;
        printf("%d\n",solve(e));
    }
}