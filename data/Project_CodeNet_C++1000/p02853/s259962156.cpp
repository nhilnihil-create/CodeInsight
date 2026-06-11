#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int ret = 0;
    if(x == 3)  ret += 100000;
    if(x == 2)  ret += 200000;
    if(x == 1)  ret += 300000;
    if(y == 3)  ret += 100000;
    if(y == 2)  ret += 200000;
    if(y == 1)  ret += 300000;
    if(x+y == 2)    ret += 400000;
    cout << ret << endl;
    return 0;
}