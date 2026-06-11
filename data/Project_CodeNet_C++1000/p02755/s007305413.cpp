#include<iostream>

using namespace std;

const double tax8 = 0.08;
const double tax10 = 0.1;

int main(){
    int a,b;
    cin >> a >> b;
    for(int price=1;price <= 1009;price++){
        if(a == (int)(tax8*price) && b == (int)(tax10*price)){
            cout << price << endl;
            return 0;
        } 
    }
    cout << -1 << endl;
    return 0;
}