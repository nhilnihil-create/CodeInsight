#include <cstdio>
#include <algorithm>

int main(){
    int w[100000];
    int i,n,k;
    long long int maxw=0;
    long long int sumw=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",w+i);
        sumw+=w[i];
        if(w[i]>maxw)maxw=w[i];
    }
    long long int avgp=(sumw-1)/k+1;
    long long int p = std::max(avgp,maxw);
    long long int load;
    int truck;
    while(true){
        truck = 1;
        load = 0;
        for(i=0;i<n;i++){
            if(load+w[i]>p){
                truck++;
                load=w[i];
            }else{
                load+=w[i];
            }
        }
        if(truck>k){
            p++;
            continue;
        }
        break;
    }
    printf("%d\n",p);
    return 0;
}

