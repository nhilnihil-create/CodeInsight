#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
    long long h;
    cin>>h;
    
    long long cnt=1;
    
    while(h>1){
        h=h/2;
        cnt++;
    }
    
    long long ans=pow(2,cnt)-1;
    cout<<ans<<endl;
    
    return 0;
}