#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

    ll N;
    cin >> N;
    if(N == 2){
        cout << 1 << "\n";
        return 0;
    }

    int c = 1;
    for(ll i = 2; i * i <= N; i++){
        if(N % i == 0){
            ll n = N;
            while(n % i == 0)
                n /= i;
            n %= i;
            if(n == 1)
                c++;
            
            ll j = N / i;
            if(j == i) continue;
            n = N;
            while(n % j == 0)
                n /= j;
            n %= j;
            if(n == 1)
                c++;
        }
    }
    N--;
    for(ll i = 2; i*i <= N; i++){
        if(N % i == 0){
            c++;
            ll j = N / i;
            if(j != i) c++;
        }
    }
    c++;

    cout << c << "\n";
    return 0;
}