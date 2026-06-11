#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];

int sieve(int n){
  for(int i=2;i<1000001;i++){
    prime[i]=true;
  }
  prime[0]=false;
  prime[1]=false;
  for(long long i=2;i<1000001;i++){
    if(prime[i]==true){
        for(long long j=i*i;j<1000001;j+=i){
            prime[j]=false;
        }
    }
    if(i==n && prime[n]==true){
        return n;
    }else if(prime[i]==true && i>n){
        return i;
    }
  }
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",sieve(n));
    return 0;
}

