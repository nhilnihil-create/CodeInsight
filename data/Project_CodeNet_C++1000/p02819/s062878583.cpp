#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(int x){
    for(int i=2; i*i<=x; i++){
        if(i != x && x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int x;
    cin >> x;
    while(1){
        if(is_prime(x)){
            cout << x << endl;
            break;
        }
        x++;
    }
}