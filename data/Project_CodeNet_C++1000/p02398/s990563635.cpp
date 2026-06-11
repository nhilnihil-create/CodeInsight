#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;  // a < b となっている
    int divisor = 0;  // divisor = 約数
    
    for(int i = a; i <= b; i++){ // a+1ずつするようになっている
        if((c % i) == 0) divisor += 1;
        else continue;
    }
    
    cout << divisor << endl;
    
    
    return 0;
}
