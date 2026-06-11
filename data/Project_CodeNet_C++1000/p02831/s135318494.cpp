#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if(a%b==0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    long long a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
    return 0;
}