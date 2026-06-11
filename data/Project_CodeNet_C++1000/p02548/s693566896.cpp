#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    long long int ans=0,a,b;
    scanf("%d",&n);

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(i*j>=n) break;
            ans++;
        }
    }


    printf("%lld\n",ans);
}

int main(){
    solve();
    return 0;
}
