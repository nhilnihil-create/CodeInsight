#include <cstdio>
int n,k,c,f[200003][2];
char s[200003];
int main(){
    scanf("%d%d%d%s",&n,&k,&c,s+1);
    int i,j=0;
    for(i=1;i<=n;i++){
        if(s[i]=='o'&&i>j) f[i][0]=f[i-1][0]+1,j=i+c;
        else f[i][0]=f[i-1][0];
    }
    j=n+1;
    for(i=n;i>=1;i--){
        if(s[i]=='o'&&i<j) f[i][1]=f[i+1][1]+1,j=i-c;
        else f[i][1]=f[i+1][1];
    }
    for(int i=1;i<=n;i++) if(f[i-1][0]+1+f[i+1][1]==k) printf("%d\n",i);
    return 0;
}