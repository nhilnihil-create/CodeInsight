#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int r = x / 100;
    x %= 100;
    int count = 0;
    while(x >= 5){
        x -= 5;
        count ++;
    }
    while(x >= 4){
        x -= 4;
        count++;
    }
    while(x >= 3){
        x -= 3;
        count++;
    }
    while(x >= 2){
        x -= 2;
        count++;
    }
    while(x >= 1){
        x--;
        count++;
    }
    if(count <= r)
        cout << '1' << endl;
    else cout << '0' << endl;
    return 0;
}