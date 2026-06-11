#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxm=2e6+5;
char s[maxm];
int n,k;
signed main(){
    cin>>n>>k;
    scanf("%s",s+1);
    int ans=0;
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1])ans++;
    }
    ans=min(ans+k*2,n-1);
    cout<<ans<<endl;
    return 0;
}
