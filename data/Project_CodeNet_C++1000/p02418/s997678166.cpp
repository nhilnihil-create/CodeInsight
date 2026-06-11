#include <stdio.h>
#include <string.h>
#define REP(i,n) for(i=0;i<(int)(n);i++)

char s[400],p[400];
int slength = 0; int plength = 0;

int solve(int a,int b){
    //printf("%d %d\n",a,b );
    if(b==plength)  return 1;
    if(slength*2-plength<a) return 0;
    if(s[a+b]==p[b]) return solve(a,b+1);
    else return solve(a+1,0);
}

int main(){
    scanf("%s",s);
    scanf("%s",p);
    //get s,p length
    int i;
    plength = strlen(p);
    slength = strlen(s);
    //s kurikaesi
    REP(i,slength) s[i+slength] = s[i];
    //printf("%d\n",slength );
    if(solve(0,0)==1) printf("Yes\n");
    else printf("No\n");


}