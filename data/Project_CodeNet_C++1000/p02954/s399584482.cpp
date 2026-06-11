#include <bits/stdc++.h>
char s[200000];
int keep[200000];
int main(){

    scanf("%s",s);
    int l,r,p,cntr=0,cntl,n=strlen(s);
    for(int i=0;i<n;i++) keep[i]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='R'&&s[i+1]=='L'){
            keep[i+1]+=(cntr+1)/2;
            keep[i]+=(cntr-(cntr+1)/2);
            cntr=0;
        }else if(s[i]=='R'&&s[i+1]=='R'){
            keep[i]=0;
            cntr++;
        }else if(s[i-1]=='R'&&s[i]=='L'){
            cntl=0;
            p=i;
        }else if(s[i-1]=='L'&&s[i]=='L'){
            cntl++;
            keep[i]=0;
            if(!(cntl%2))
                keep[p]++;
            else
                keep[p-1]++;
        }
    }
    for(int i=0;i<n-1;i++)
        printf("%d ",keep[i]);
    printf("%d",keep[n-1]);
}