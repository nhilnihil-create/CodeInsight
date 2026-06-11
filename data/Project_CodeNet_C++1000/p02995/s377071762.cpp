#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;



int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long tmp1=c,tmp2=d;
    if(tmp1>tmp2)swap(tmp1,tmp2);
    while(tmp1>0){
        long long x=tmp1;
        tmp1=tmp2%tmp1;
        tmp2=x;
    }
    long long GCD=c/tmp2*d;
    long long ans=b-(a-1);
    ans-=b/c-(a-1)/c;
    ans-=b/d-(a-1)/d;
    ans+=b/GCD-(a-1)/GCD;
    cout<<ans<<endl;
    return 0;
}