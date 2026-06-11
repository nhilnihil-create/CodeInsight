#include<iostream>
using namespace std;
constexpr auto mod=1000000000+7;
long long quick_pow(long long radix,long long ex){
    long long res=1;
    while(ex>0){
        if(ex & 1)
            res=res*radix%mod;
        radix=radix*radix%mod;
        ex>>=1;
    }
    return res;
}
int main(){
    long long n;
    cin>>n;
    cout<<((quick_pow(10,n)-quick_pow(9,n)+mod)-quick_pow(9,n)+mod+quick_pow(8,n))%mod;
    //getchar();
    //getchar();
    return 0;
}