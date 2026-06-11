#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isprime(int n){
    double rootn = sqrt(n);
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else if (n % 2 == 0){
        return false;
    }
    else{
        for(int i = 3; i <= rootn; i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}


int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int Ai;
        cin >> Ai;
        N -= Ai;
    }
    if(N < 0){
        cout << -1 << endl;
    }
    else{
        cout << N << endl;
    }
    return 0;
}