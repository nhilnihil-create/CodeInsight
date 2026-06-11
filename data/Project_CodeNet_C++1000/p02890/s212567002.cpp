#include<cstdio>
const int N = 3e5+5;
int a[N];
int amount[N];
int cnt[N];
long long sumValue[N];
int sumCnt[N];

//cnt[i], 第i种牌有几张
//amount[i], 数量等于i的牌有几种
//sumCnt[i], 数量小于等于i的有几种
//sumValue[i], 数量小于等于i的种类的cnt之和

//n错了
int judge(long long k,long long m,long long n){
    //printf("k = %lld, m = %lld\n",k,m);
    long long left = k-(n-sumCnt[m-1]);
    if(sumValue[m-1]>=left*m){ 
        //printf("sumValue[%d] = %lld, %lld*%lld = %lld\n",m-1,sumValue[m-1],left,m,left*m);
        //printf("Yep\n");
        return 1;
    }
    else{ 
        //printf("Nope\n");
        return 0;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);  
        cnt[a[i]]++;
    }
    for(int i = 1; i <= n; i++) amount[cnt[i]]++;
    /*for(int i = 1; i <= n; i++){
        printf("amount[%d] = %d\n",i,amount[i]);   
    }*/
    sumCnt[0] = 0;
    for(int i = 1; i <= 300000; i++){
        sumCnt[i] = sumCnt[i-1]+amount[i];
        sumValue[i] = sumValue[i-1]+(long long)amount[i]*(long long)i;
    }
    int total = sumCnt[300000];
    for(int k = 1; k <= n; k++){
        int l = 1, r = n/k;
        int res = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(judge(k,m,total)){
                res = m;
                l = m+1;
            }
            else r = m-1;
        }
        printf("%d\n",res);
    }
    return 0;
}