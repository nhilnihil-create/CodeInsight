#include <bits/stdc++.h>

using namespace std;

long long INF=1e15;

int prime[2000000];
bool is_prime[2000000];

int sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i)is_prime[j]=false;
        }
    }
    return p;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        int n;
        cin>>n;

        if(n==0)break;

        cout<<sieve(2*n)-sieve(n)<<endl;

    }
}
