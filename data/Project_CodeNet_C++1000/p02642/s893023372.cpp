#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXVAL 1000005
int a[MAXN];
int f[MAXVAL];  //1:0->1×ÔÉí³öÏÖ1´Î£¬1->2»ò0->2 ±»±ðµÄÊýÕû³ý 
int n, ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    if(a[1] == 1){
    	if(a[2] == 1)
    		printf("%d\n", 0);
        else
			printf("%d\n", 1);
        return 0;
    }
    for(int i = 1; i <= n; i++){
        int j = a[i];
        if(f[j] == 0)
            f[j] = 1;
        else if(f[j] == 1)
            f[j] = 2;
        for(int k = 2*j; k < MAXVAL; k+= j)
            f[k] = 2; 
    }
    for(int i = 1; i <= n; i++)
        if(f[a[i]] == 1)
            ans++;
    printf("%d\n", ans);
}