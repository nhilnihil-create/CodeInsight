#include <iostream>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i <=n ;i++){
        if(n % i == 0) return false;
    }
    return n != 1;
}

int main(){
    int n;
    while(cin >> n, n){
        int ans = 0;
        for(int i = n + 1; i <= 2 * n; i++){
            if(isPrime(i)) ans++;
        }
        cout << ans << endl;
    }
}