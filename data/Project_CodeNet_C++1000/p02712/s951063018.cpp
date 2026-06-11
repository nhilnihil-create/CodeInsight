#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long ans=n*(n+1)/2;
    ans-=(n/5)*(n/5+1)/2*5;
    ans-=(n/3)*(n/3+1)/2*3;
    ans+=(n/15)*(n/15+1)/2*15;
    printf("%lld\n",ans);

}

