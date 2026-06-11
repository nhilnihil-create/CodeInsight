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

int x[10000000];
int G[20];
int v,w,n,m,cnt=0;

int insertionSort(int x[],int n,int g) {
    for (int i=g;i<n;i++) {
        v=x[i];
        w=i-g;
        while (w>=0 && x[w]>v) {
            x[w+g]=x[w];
            w=w-g;
            cnt++;
        }
        x[w+g]=v;
    }

}

int shellSort(int x[],int n) {
    cnt=0;
    for (int h=0;h<20;h++) {
        if (G[h]>n) {
            m=h;
            break;
        }
    }
    printf("%d\n",m);
    for (int h=m-1;h>=0;h--) {
        printf("%d",G[h]);
        if (h) {
            printf(" ");
        }
        insertionSort(x,n,G[h]);
    }
    printf("\n");
}



int main(){
    double pai=3.141592653589;
    G[0]=1;
    for (int i=1;i<20;i++) {
        G[i]=G[i-1]*3+1;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    shellSort(x,n);
    printf("%d\n",cnt);
    for(int i=0;i<n;i++){
        printf("%d\n",x[i]);
    }
    return 0;
}