#include<bits/stdc++.h>

using namespace std;

char s[1005], t[1005];

int main(){
    cin>>s+1>>t+1;
    int n=strlen(s+1);
    int m=strlen(t+1);

    int res=0x3f3f3f3f;
    for(int i=1;i+m-1<=n;++i){
        int cnt=0;
        for(int j=1;j<=m;++j){
            if(s[i+j-1]!=t[j]){
                ++cnt;
            }
        }
        res=min(res,cnt);
    }

    cout<<res;

    return 0;
}
