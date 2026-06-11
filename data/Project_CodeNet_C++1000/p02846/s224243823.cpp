#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int t1,t2;
    ll a1,b1,a2,b2;
    cin>>t1>>t2;
    cin>>a1>>a2>>b1>>b2;
    if(a1<b1) swap(a1,b1),swap(a2,b2);

    ll s1=t1*a1+t2*a2;
    ll s2=t1*b1+t2*b2;
    if(s1==s2){
        printf("infinity\n");
        return 0;
    }
    if(s1>s2){
        printf("0\n");
        return 0;
    }
    ll len=t1*(a1-b1);
    ll d=s2-s1;

    ll ans=1+2*(len/d)-(len%d==0);
    printf("%lld\n", ans);

    return 0;
}