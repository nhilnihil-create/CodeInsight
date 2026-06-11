#include <iostream>
using namespace std;

int A[200010];

main() {
    int N;
    cin>>N;
    for (int i=0;i<N;++i) cin>>A[i];
    long long ans=0;
    for (int i=1;i<N;++i) {
        int add=max(0,A[i-1]-A[i]);
        ans+=add;
        A[i]+=add;
    }
    cout<<ans<<endl;
}