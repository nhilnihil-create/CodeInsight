#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    if(360 % x == 0){
        cout << 360 / x << endl;
    }else{
        for(int k=1; k<=360; k++){
            if((x*k) % 360 == 0){
                cout << k << endl;
                return 0;
            }
        }
    }
    return 0;
}