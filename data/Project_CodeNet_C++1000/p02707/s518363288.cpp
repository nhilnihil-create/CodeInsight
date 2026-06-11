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
    int N;
    cin >> N;
    int a[N+1] = {0};
    for(int i=2; i<=N; i++){
        int Ai;
        cin >> Ai;
        a[Ai]++;
    }
    for(int i=1; i<=N; i++){
        cout << a[i] << endl;
    }
    return 0;
}