#include<bits/stdc++.h>

using namespace std;

int main(){
    int e;
    while(cin>>e,e){
        int ans=1e9;
        for(int i=0;i*i*i<=e;++i){
            int e1=e-i*i*i;
            for(int j=0;j*j<=e1;++j){
                int k=e1-j*j;
                ans=min(ans,i+j+k);
            }
        }
        cout<<ans<<endl;
    }
}