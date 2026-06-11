#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using itn = int;

int main(void){
    int x;
    cin >> x;
    
    for(int i = 1;i <= 10000;i++){
        if(i * x % 360 == 0){
            cout << i << endl;
            break;
        }
        /*if(i * (180 - x) % 360 == 0){
            cout << i << endl;
            break;
        }*/
    }
    
    //cout << ans << endl;
}