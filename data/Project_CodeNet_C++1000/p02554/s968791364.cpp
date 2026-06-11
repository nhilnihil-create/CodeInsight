#include<iostream>
using namespace std;
long long m=1000000000+7;
int main(){
    long long n;
    cin>>n;
    long long a=1,b=1,c=1;
    for(int i=0;i<n;i++){
        a=(a*10)%m;
        b=(b*8)%m;
        c=(c*9)%m;
    }
    long long ans=(a-2*c+b)%m;
    if(ans<0) ans+=m;
    cout<<ans<<endl;
    return 0;
}