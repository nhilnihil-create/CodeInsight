#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,ans;
    cin>>N;
    if(N%1000 == 0)cout<<0<<endl;
    else{
        ans = (N/1000+1)*1000-N;
        cout<<ans<<endl;
    }
    return 0;
}