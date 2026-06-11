#include <iostream>
using namespace std;

int N,P,A;
long long ans;

main() {
    cin>>N;
    for (int i=0;i<N;++i) {
        cin>>A;
        if (P<=A) P=A;
        else ans+=P-A;
    }
    cout<<ans<<endl;
}