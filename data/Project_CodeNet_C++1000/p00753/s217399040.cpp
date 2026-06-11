#include <iostream>
using namespace std;

#define MAXN 300000

bool isNotPrime[MAXN];
int primeNum[MAXN];

void checkNumber(int n){
    isNotPrime[n] |= false;
    for(int i = 2; n*i < MAXN; i++){
        isNotPrime[i*n] = true;
    }
}

int main(int argc, const char * argv[]) {
    isNotPrime[1] = true;
    primeNum[2] = 1;
    
    checkNumber(2);
    for(int i = 3; i < MAXN; i++){
        primeNum[i] = primeNum[i-1];
        if(!isNotPrime[i]){
            checkNumber(i);
            primeNum[i]++;
        }
    }
    
    while(1){
        int n; cin >> n;
        if(!n) break;
        
        cout << primeNum[2*n] - primeNum[n] << endl;
    }
}