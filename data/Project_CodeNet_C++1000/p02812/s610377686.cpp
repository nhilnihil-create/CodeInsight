#include<bits/stdc++.h>
using namespace std;

int main(){
    int mod=1000000007;
    int n,ans=0;
    char s[55];
    for (int i=0;i<55;i++) s[i]='X';
    scanf("%d",&n);
    scanf("%s",s);
    for (int i=0;i<n;i++) if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') ans++;
    printf("%d\n",ans);
    return 0;
}
