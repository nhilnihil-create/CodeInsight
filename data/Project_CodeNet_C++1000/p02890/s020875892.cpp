#include <bits/stdc++.h>

using namespace std;
int n;
const int maxn = 3e5+5;
int sum[maxn];
int fuck[maxn];
int main()
{
    scanf("%d", &n);
    memset(sum,0,sizeof(sum));
    memset(fuck,0,sizeof(fuck));
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        sum[x]++;
        fuck[sum[x]]++;
    }
    for(int i=1;i<=n;i++)
        fuck[i]+=fuck[i-1];
    int now = n;
    for(int i=1;i<=n;i++){
        while(fuck[now]<i*now){
            now--;
        }
        printf("%d\n", now);
    }
    return 0;
}
