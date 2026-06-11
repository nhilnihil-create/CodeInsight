#include<bits/stdc++.h>
using namespace std;
bool isprime(long long n);
int main(){
    int x;
    cin>>x;
    bool flag=false;
    while(!flag){
        flag=isprime(x);
        if(flag){
            cout<<x<<"\n";
            return(0);
        }
        x++;
    }
    return(0);
}
bool isprime(long long n){
    if(n==2) return(true);
    if(n<=1||n%2==0) return(false);
    for(long long i=3;i*i<=n;i+=2){
        if(n%i==0) return(false);
    }
    return(true);
}