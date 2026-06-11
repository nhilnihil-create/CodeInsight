#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;


bool isPrime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int x;
    cin >> x;

    reps(i,x,200000){
        if(isPrime(i)){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}