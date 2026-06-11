#include <bits/stdc++.h>
using namespace std;
string a,b;
int dian;
char c[100],d[100],ans[100];
void mut(string a,string b){
    int la=a.length();
    int lb=b.length();
    int x=0;
    for(int i=0;i<la;i++)
        c[la-i-1]=a[i]-'0';
    for(int i=0;i<lb;i++)
        d[lb-i-1]=b[i]-'0';
    for(int i=0;i<la;i++){
        x=0;
        for(int j=0;j<lb;j++){
            ans[i+j]=ans[i+j]+x+c[i]*d[j];
            x=ans[i+j]/10;
            ans[i+j]=ans[i+j]%10;
        }
        ans[i+lb]=x;
    }
    int lc=la+lb;
    while(lc>1&&ans[lc-1]==0)
        lc--;
    if(lc<dian)
        printf("0");
    for(int i=lc-1;i>=dian;i--)
        printf("%d",ans[i]);
}
int main()
{
    cin>>a>>b;
    int lb=b.length();
    string tmp="";
    for(int i=0;i<lb;i++){
        if(i==0&&b[i]=='0')continue;
        if(b[i]!='.')
            tmp+=b[i];
        else{
            dian=lb-i-1;
        }
    }
    mut(a,tmp);
    return 0;
}
