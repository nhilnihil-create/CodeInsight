#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,d,ans=0;
    cin>>m>>d;
    for(int i=1;i<=m;i++){
        for(int j=10;j<=d;j++){
            int x=j%10,y=j/10;
            if(x<2||y<2) continue;
            if(x*y==i) ans++;
        }
    }
    cout<<ans;
}