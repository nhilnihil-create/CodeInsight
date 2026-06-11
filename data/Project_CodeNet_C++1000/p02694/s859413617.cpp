#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    long long int a, cnt = 0, money = 100;
    cin >> a ;

    while(1){
        money += money / 100;
        cnt++;
        if(money >= a){
            break;
        }
        
    }

    cout << cnt << endl;

    return 0; 
}
