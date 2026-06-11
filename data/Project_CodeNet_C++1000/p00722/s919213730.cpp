#include<bits/stdc++.h>
using namespace std;

bool isprime(long long int val) {
    if (val <= 1)return false;
    for (long long int i = 2; i*i <= val; i++) {
        if (val%i == 0LL)return false;
    }
    return true;
}

int main(){
    long long a,d,n;
    while(cin>>a>>d>>n){
        if(a==0 && d==0 && n==0){
            break;
        }
        long long ans=0;
        int cnt=0;
        if(isprime(a)) cnt++;
        while(cnt!=n){
            a+=d;
            if(isprime(a)) cnt++;
        }
        cout<<a<<endl;

    }
    
}
