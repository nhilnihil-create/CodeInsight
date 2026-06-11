#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin>>A[i];

    long long ans=0,tmp=0;
    for(int i=0; i<N; ++i){
        tmp = max(tmp, A[i]);
        ans += tmp - A[i];
    }
    cout<<ans<<endl;
}
