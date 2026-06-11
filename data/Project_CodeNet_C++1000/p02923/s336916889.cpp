#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;cin>>N;
    long long H[N];
    for(long long i=0;i<N;i++){
        cin>>H[i];
    }
    long long ans=0;
    long long tmp=0;
    for(long long i=1;i<N;i++){
        if(H[i]<=H[i-1]){
            tmp++;
        }
        else{
            ans=max(ans,tmp);
            tmp=0;
        }
    }
    ans=max(ans,tmp);
    cout<<ans<<endl;
    return 0;
}