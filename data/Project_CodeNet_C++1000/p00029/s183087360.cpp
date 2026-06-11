#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void){
    char *l,*m,t[33];
    char s[500][33];
    int c[500]={0},n=0,cnt=0,max=0,lm=0;
    while(scanf("%s",s[n++])!=EOF)if(s[n-1][0]=='0')break;
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            if(i!=j && strcmp(s[i],s[j])<0){
                strcpy(t,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],t);
            }
        }
    }
    for(int i=0;i<n;i++){
        int ln = strlen(s[i]);
        if(ln>lm){
            m=s[i];
            lm = ln;
        }
        if(i==0)continue;
        if(strcmp(s[i],s[i-1])==0){
            cnt++;
            if(cnt>max){
                max=cnt;
                l = s[i];
            }
        }else cnt = 0;
    }
    printf("%s %s\n",l,m);
    return 0;
}