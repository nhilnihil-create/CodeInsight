#include<iostream>
#include<cstdio>
#define MAXAMOUNT 100000
int MAXNUM = 100000;
int MAXWEIGHT = 10000;
int amount,num;
long long list[MAXAMOUNT];

int check(int value){
    int sum = 0;
    int checkNum = 1;
    for(int i = 0;i<amount;i++){
        if(list[i] > value){
            return 0;
        }
        sum += list[i];
        if(sum > value){
            checkNum++;
            sum = list[i];
            if(checkNum > num){
                return 0;
            }
        }
    }
    return 1;
}

int binarySearch(){
    int min = 0;
    long long max = MAXAMOUNT * MAXWEIGHT;
    while(max-min > 1){
        int center = (min + max) / 2;
        if(check(center)==1){
            max = center;
        }
        else{
            min = center;
        }
    }
    return max;
}

int main(){
    scanf("%d%d",&amount,&num);
    int temp;
    for(int i=0;i<amount;i++){
        scanf("%d",&temp);
        list[i] = temp;
    }
    printf("%d\n",binarySearch());
}
