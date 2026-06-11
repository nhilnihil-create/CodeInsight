#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n,m,ans=0,cnt=1;
string s;
int main(){
    scanf("%d%d",&n,&m);
    cin>>s;
    char pre=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==pre)ans++;
        else pre=s[i],cnt++;
    }

    if(cnt-m*2>=1)cnt-=m*2;
    else cnt=1;
    printf("%d\n",n-cnt);
    return 0;
}