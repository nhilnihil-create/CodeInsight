#include <iostream>
using namespace std;
int main(void){
    long long n,a,b;
    cin>>n>>a>>b;
    long long ans;
    long long c=n%(a+b);
    if(c>=a){
        ans=n/(a+b)*a+a;
    }
    else{
        ans=n/(a+b)*a+c;
    }
    cout<<ans<<endl;
}

