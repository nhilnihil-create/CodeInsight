#include <cstdio>

#define sz 8
char mp[sz][sz];

int main(){
    int h,w,k;
    scanf("%d %d %d",&h,&w,&k);
    for(int i=0;i<h;i++) scanf("%s",mp[i]);

    int ans=0;

    for(int m1=0;m1<(1<<h);m1++){
        for(int m2=0;m2<(1<<w);m2++){
            int cnt=0;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(mp[i][j]=='#' && ((m1 & (1<<i))==0) && ((m2 & (1<<j))==0)) cnt++;
                }
            }
            if(cnt==k) ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
