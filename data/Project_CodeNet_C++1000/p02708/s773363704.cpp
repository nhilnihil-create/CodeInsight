#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n,k;cin>>n>>k;
    long long ans=0;
    const int MOD=1000000007;

    for(long long i=k;i<=n+1;i++){
        long long low=(i+1)*i/2;
        long long tmp=n-i+1;
        long long high=(n+2)*(n+1)/2 -(tmp+1)*tmp/2;
        ans+=high-low+1;
        ans%=MOD;
        //cout<<high-low+1<<endl;
    }
    cout<<ans<<endl;


    return 0;
}
