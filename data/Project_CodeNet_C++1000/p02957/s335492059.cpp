#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    bool flg = false; 
    for(int k = 0; k <= 1000000000; k++){
        if(abs(a - k) == abs(b - k)){
            flg = true;
            cout << k << endl;
            break; 
        }
    }
    if(!flg) cout << "IMPOSSIBLE" << endl;
    return 0;
}