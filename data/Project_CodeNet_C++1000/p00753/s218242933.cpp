#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i,n) for(int i=0;i<(n);i++)

using namespace std;


int segment_sieve(long a, long b){
    bool is_prime_small[b+1];
    bool is_prime[b+1];
    for(long i=0; i*i <= b; i++) is_prime_small[i] = true;
    for(long i=0; i<b-a; i++) is_prime[i] = true;

    for(long i=2; i*i<=b; i++){
        if(is_prime_small[i]){
            for(long j=2*i; j*j<=b;j+=i) is_prime_small[j] = false;
            for(long j=((a+i) / i ) *i; j<=b; j+=i) is_prime[j-a-1]=false;
        }
    }
    int cnt=0;
    REP(i,b-a){
        if(is_prime[i]) cnt++;
    }
    return cnt;
}

int main(){
    long n;
    while(cin >> n){
        if(n==0) break;
        int res = segment_sieve(n, 2*n);
        cout << res << endl;
    }
    return 0;
}