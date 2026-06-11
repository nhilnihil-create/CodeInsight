#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int m,d;
    cin>>m>>d;
    int ans=0;
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=d; ++j){
            int x=j%10,y=j/10;
            if(x>=2&&y>=2&&x*y==i)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}