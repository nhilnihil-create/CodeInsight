#include <bits/stdc++.h>
using namespace std;

bool prime (long long x){
    if(x <= 1)
       {return false;}
    for(long long i = 2; i*i <= x; i++){
        if(x % i == 0)
           {return false;}
    }
    return true;
}
int main(){
    long long x;
    cin >> x;
    while(true){
        if(prime (x)){
            cout << x <<endl;
            return 0;}
        x++;}}
