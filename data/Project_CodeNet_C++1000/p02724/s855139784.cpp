#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    long long X;
    cin>>X;
    long long r=X%500;
    long long p=X/500;
    long long ans=p*1000+(r/5)*5;
    cout<<ans<<endl;

    return 0;
}