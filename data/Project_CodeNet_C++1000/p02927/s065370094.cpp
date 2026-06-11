#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,d,ans=0;
    cin>>m>>d;
    for(int k=4;k<=m;k++){
        for(int i=2;i<=9;i++){
            for(int j=2;j<=9;j++){
                if(i*j==k&&i*10+j<=d){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}