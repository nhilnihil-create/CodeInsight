#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
char s[max_n];
int main(){
    scanf(" %s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)if(s[i]=='?')s[i]='D';
    printf("%s\n",s+1);
    return 0;
}