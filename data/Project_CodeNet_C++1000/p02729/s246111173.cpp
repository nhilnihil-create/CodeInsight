#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;

    int ans=N*(N-1)/2;
    ans+=M*(M-1)/2;

    cout<<ans<<endl;
    

    return 0;
}