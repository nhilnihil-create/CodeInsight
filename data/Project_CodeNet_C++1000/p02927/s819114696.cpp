#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int m,d;
    cin>>m>>d;
    int ans=0;
    for(int i=4; i<=m; ++i){
        for(int j=22; j<=d; ++j){
            if(j%10<=1)continue;
            if(i==(j/10)*(j%10))ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
