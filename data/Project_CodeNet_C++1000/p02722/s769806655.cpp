#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long x=0;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            long long N=n;
            while(N%i==0)N/=i;
            if(N%i==1)x++;
        }
    }
    n--;
    long long yakusu=1;
    for(long long i=2;i*i<=n;i++){
        int p=0;
        while(n%i==0){
            n/=i;
            p++;
        }
        yakusu*=p+1;
    }
    if(n>1)yakusu*=2;
    cout<<x+yakusu<<endl;
    return 0;
}
