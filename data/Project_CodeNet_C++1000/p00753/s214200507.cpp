#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n);

vector<int> sieve(int n){
    vector<int> primes(n);
    for(int i=2; i<n; i++){
        primes[i] = i;
    }
    for(int i=2; i*i<n; i++){
        if(primes[i]){
            for(int j=i*i; j<n; j+=i){
                primes[j] = 0;
            }
        }
    }
    return primes;
}

int main(){
    int n;
    vector<int> primes = sieve(250000);
    while(cin >> n, n != 0){
        int cnt = 0;
        for(int i = n+1; i<=2*n; i++){
            if(primes[i] != 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}