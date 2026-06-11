#include <iostream>
using namespace std;
 
bool primes[100000000];
 
void Sieve(){
    for(int i= 2; i < 10000000; i++){
        primes[i] = true;
    }
    primes[1] = false;    
    for(int i = 2; i < 10000; i++){
        if(primes[i] == true)
            for(int j=i; j*i < 100000000;j++){
                primes[j*i] = false;
            }
    }     
}
bool IsPrime(int x){
    return primes[x];
}
 
int main(void){
    Sieve();
    int n, c;
    for(int k = 1; k > 0; k++){
        cin >> n;
        if(n == 0) break;
        c = 0;
        for(int i = n + 1; i <= 2 * n; i++){
        if(IsPrime(i)==true)
            c++;
        }
        cout << c << endl;
    }
    return 0;
}
