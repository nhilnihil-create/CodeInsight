#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)

int main(){
    ll a, b, c, k, sum = 0;

    sll(a), sll(b), sll(c), sll(k);

    if(a >= k){
        sum += k;
        k = 0;
    }else{
        sum += a;
        k -= a;
    }

    if(b >= k){
        k = 0;
    }else{
        k -= b;
    }

    if(c >= k){
        sum -= k;
    }else{
        sum -= c;
    }

    cout << sum << endl;

    return 0;
}