#include <bits/stdc++.h>
using namespace std;
int main(void){

    long long a, sum = 0 ;
    cin >> a ;
    
    for(int i = 3; i <= a; i += 3){
        sum += i;
    }
    
    for(int i = 5; i <= a; i += 5){
        sum += i;
    }
    
    for(int i = 15; i <= a; i += 15){
        sum -= i;
    }
    
    cout << a * ( a + 1 ) / 2 - sum << endl;

}
