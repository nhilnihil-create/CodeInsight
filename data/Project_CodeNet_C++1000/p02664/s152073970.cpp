#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
char s[N];int n;
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=1;i<=n;i++)if(s[i]=='?')s[i]='D';
    puts(s+1);
    return 0;
}