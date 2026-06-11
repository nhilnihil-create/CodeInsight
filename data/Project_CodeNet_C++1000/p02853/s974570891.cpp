#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x >>y;
    int count=0;
    if(x==1&&y==1){
        count += 400000;
    }
    if(x==1){
        count += 300000;
    }
    else if(x==2){
        count += 200000;
    }
    else if(x==3){
        count += 100000;
    }
    if(y==1){
        count += 300000;
    }
    else if(y==2){
        count += 200000;
    }
    else if(y==3){
        count += 100000;
    }
    cout << count;
    return 0;
}