#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans;
    bool a=false;
    cin>>n;
    for(int i=1; i<=50000; i++){
        int b;
        b=i*1.08;
        if(b==n) {
            a=true;
            ans=i;
    }
}
if(a) cout<<ans<<endl;
    else cout<<":("<<endl;
}