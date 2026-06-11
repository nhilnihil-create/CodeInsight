#include <iostream>
#include <vector>
using namespace std;

int main(){
    int primes[123456*2];
    for(int i=2;i<123456*2;++i) primes[i] = 1;
    for(int i=2;i<123456*2;++i){
        if(primes[i]){
            for(int j=2;i*j<123456*2;++j) primes[i*j] = 0;
        }
    }
    while(true){
        int n;
        int cnt=0;
        cin >> n;
        if(!n) break;
        for(int i=n+1;i<=2*n;++i){
            if(primes[i]) ++cnt;
        }
        cout << cnt << endl;
    }
}