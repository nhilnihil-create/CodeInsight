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
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1])ans++;
        else cnt++;
    }
    if(cnt%2==0){
        ans+=min(cnt/2,k)*2;
    }else{
        cnt--;
        ans+=min(cnt/2,k)*2;
        k-=cnt/2;
        if(k>0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
