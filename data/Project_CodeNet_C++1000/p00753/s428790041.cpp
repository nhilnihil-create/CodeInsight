#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

#define N 300000 

bool is_prime[N];

void calc(){
    int n;
    cin >> n;
    int count = 0;
    if( n == 0 )exit(0);
    for(int p = n +1 ; p <= 2 * n ; p++ ){
        if( is_prime[p] )count++;
    }
    cout << count << endl;
}

int main(void){
    for(int i = 0 ;i < N ; i++ ){
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2 ; i < N ; i++ ){
        if( is_prime[i] ){
            for(int j = i + i ; j < N ; j += i ){
                is_prime[j] = false;
            }
        }
    }
    
    
    while(true)calc();
    return 0;
}