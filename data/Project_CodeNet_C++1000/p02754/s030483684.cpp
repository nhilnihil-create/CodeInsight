#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    ll N,A,B;
    cin>>N>>A>>B;

    ll ans=0;
    ans+=N/(A+B)*A;
    N%=(A+B);
    if(N<A){
        ans+=N;
    }else{
        ans+=A;
    }
    cout<<ans<<endl;

    return 0;
}