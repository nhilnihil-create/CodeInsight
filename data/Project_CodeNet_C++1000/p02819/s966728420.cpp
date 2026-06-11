#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int prime(int x){
    if(x == 2){
        return true;
    }else if(x % 2 == 0){
        return false;
    }
    double sqi = sqrt(x);
    for(int j = 3; j <= sqi; j+=2){
        if(x % j == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int x;
    cin >> x;
    for(int i = x; i <= 110000; i++){
        if(prime(i)){
            cout << i << endl;
            return 0;
        }        
    }
    return 0;
}