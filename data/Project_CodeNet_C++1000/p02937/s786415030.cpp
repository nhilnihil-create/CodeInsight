#include <bits/stdc++.h>
using namespace std;
char s[100005], t[100005];
int nt[100005][26];
int main(){
    scanf("%s%s", s+1, t+1);
    int n = strlen(s+1), m = strlen(t+1);
    for(int i=n;i>=1;i--){
        for(int j=0;j<26;j++) nt[i][j] = nt[i+1][j];
        nt[i][s[i]-'a'] = i;
    }
    long long ans = 0;
    int cur = 1;
    for(int i=1;i<=m;i++){
        if(nt[cur][t[i]-'a'] == 0){
            if(nt[1][t[i]-'a'] == 0){
                printf("-1\n");
                return 0;
            }
            ans += n-cur+1;
            ans += nt[1][t[i]-'a'] - 1 + 1;
            cur = nt[1][t[i]-'a'] + 1;
        }
        else{
            ans += nt[cur][t[i]-'a'] - cur + 1;
            cur = nt[cur][t[i]-'a']+1;
        }
    }
    printf("%lld\n", ans);
}