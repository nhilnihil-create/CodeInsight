#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=1000005;
char s[max_n];
int n,a[max_n];
int solve(){
    int res=0;
    for(int i=0;i<n;i++)if((i&(n-1))==i)res+=a[i];
    return res&1;
}
int main(){
    scanf("%d %s",&n,s);
    for(int i=0;i<n;i++)a[i]=s[i]-'1';
    if(solve())printf("1\n");
    else{
        bool f=false;
        for(int i=0;i<n;i++)f|=a[i]==1;
        if(f)printf("0\n");
        else{
            for(int i=0;i<n;i++)a[i]/=2;
            if(solve())printf("2\n");
            else printf("0\n");
        }
    }
    return 0;
}