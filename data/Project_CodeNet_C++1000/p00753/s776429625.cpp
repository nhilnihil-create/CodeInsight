#include <bits/stdc++.h>
using namespace std;
const int MAX_N=123456*2;
bool is_prime[MAX_N+1];
int sum[MAX_N+1];
int main() {
    for(int i=2;i<=MAX_N;i++) is_prime[i]=1;
    for(int i=2;i*i<=MAX_N;i++) {
        if(!is_prime[i]) continue;
        for(int j=i*2;j<=MAX_N;j+=i) is_prime[j]=0;
    }
    for(int i=2;i<=MAX_N;i++) {
        sum[i]=sum[i-1]+is_prime[i];
    }
    int n;
    while(scanf("%d",&n),n) {
        printf("%d\n",sum[2*n]-sum[n]);
    }
}