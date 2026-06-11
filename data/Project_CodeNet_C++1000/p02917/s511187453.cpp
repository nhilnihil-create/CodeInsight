#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    int B[N-1];
    for(int i=0; i<=N-2; i++) cin>>B[i];

    long long ans=B[0];
    for(int i=1; i<=N-2; i++){
        ans += min(B[i-1], B[i]);
    }
    ans += B[N-2];
    cout<<ans<<endl;
}
