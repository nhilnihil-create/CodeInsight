#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    long long N;cin>>N;
    long long ans=0;
    for(long long i=1;i<N;i++){
        ans+=i;
    }
    cout<<ans<<endl;
    return 0;
}
