#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool matched = false;
    int ans = 0;
    for(int x = 1; x <= 50000; x++){
        if(floor(x * 108 / 100) == n){
            ans = x;
            matched = true;
        }
    }

    if(matched){
        cout << round(ans) << endl;
    }else{
//        cout << round(ans) << endl;
        cout << ":(" << endl;
    }
}