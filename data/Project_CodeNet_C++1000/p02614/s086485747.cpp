#include <cstdio>
int h,w,k,ans;
char a[9][9],t[9][9];
int work(int row,int column){
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) t[i][j]=a[i][j];
    for(int i=1;i<=h;i++) if(row&(1<<i-1)) for(int j=1;j<=w;j++) t[i][j]='R';
    for(int i=1;i<=w;i++) if(column&(1<<i-1)) for(int j=1;j<=h;j++) t[j][i]='R';
    int s=0;
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) if(t[i][j]=='#') ++s;
    return s;
}
int main(){
    scanf("%d%d%d",&h,&w,&k);
    for(int i=1;i<=h;i++) scanf("%s",a[i]+1);
    for(int i=0;i<(1<<h);i++) for(int j=0;j<(1<<w);j++) if(work(i,j)==k) ++ans;
    printf("%d\n",ans);
    return 0;
}