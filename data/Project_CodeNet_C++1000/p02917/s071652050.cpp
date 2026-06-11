#include<stdio.h>
#include<algorithm>
#define INF 1<<21
using namespace std;
int main(){
    int n,sum=0;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++) s[i] = INF;
    for(int i=0;i<n-1;i++){
        scanf("%d",&s[i]);
    }
    sum += s[0];
    for(int i=1;i<n;i++){
        sum += min(s[i-1],s[i]);
    }
    printf("%d\n",sum);
}