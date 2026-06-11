#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n){
    if(n<=1) return false;
    for(long long p=2;p*p<=n;++p){
        if(n%p ==0)return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    long long ans = n;
    while(!is_prime(ans)) ++ans;
    cout<<ans<<endl;
}