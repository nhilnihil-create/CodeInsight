#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int N,M;
    long long ans=0;

    cin>>N>>M;

    if(N >=2){
        ans=ans+(N*(N-1))/2;
    }

    if(M>=2){
        ans = ans+(M*(M-1))/2;
    }

    cout<<ans<<endl;

 

    return 0;
}