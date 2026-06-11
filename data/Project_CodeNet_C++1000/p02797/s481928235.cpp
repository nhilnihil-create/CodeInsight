#include<bits/stdc++.h>
using namespace std;
int main(){
     int n, m, sum;
    scanf("%d %d %d", &n, &m, &sum);
    for (int i = 0; i < m;i++){
        printf("%d ", sum);
    }
    if(sum==2||sum==1){
        for (int i = 0; i < n - m;i++){
            printf("%d ", 3);
        }
    }
    else{
        for (int i = 0; i < n - m;i++){
            printf("%d ", sum - 1);
        }
    }
}