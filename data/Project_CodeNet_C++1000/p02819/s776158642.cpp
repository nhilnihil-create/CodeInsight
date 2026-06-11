#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


vector<bool> isPrime; // maxまでの全整数に対し素数かどうかの表
vector<ll> primes; // 素数が順に格納
ll primesP; // primesのアクセス用

void sieve(ll max){
    if(max + 1 > isPrime.size()){ // resizeで要素数が減らないように
        isPrime.resize(max + 1, true); // IsPrimeに必要な要素数を確保
    } 
    isPrime[0] = false; // 0は素数ではない
    isPrime[1] = false; // 1は素数ではない

    for(ll i = 2; i * i <= max; i++){ // 0からsqrt(max)まで調べる
        if(isPrime[i]){ // iが素数ならば
            for(ll j = 2; i * j <= max; j++){ // (max以下の)iの倍数は
                isPrime[i * j] = false; // 素数ではない
            }
        }
    }

    for(ll i = 0; i <= max; i++){ // 素数の数列を作成
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    ll X;
    cin >> X;

    sieve(1000000);

    primesP = 0;
    while(primes[primesP] < X){
        primesP++;
    }

    cout << primes[primesP] << endl;

    return 0;
}