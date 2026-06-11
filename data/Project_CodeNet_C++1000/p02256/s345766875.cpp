#include<iostream>
using namespace std;

int gcd(int x,int y){
    int max;
    if(x == y){
        return x;
    }else if(y % (x % y)==0){
        max = x % y;
        return max;
    }else{
        gcd(y,x % y);
    }
}

int main(){
    int x,y;
    cin >> x;
    cin >> y;
    if(x>=y)cout << gcd(x,y) << endl;
    if(y>x)cout << gcd(y,x) << endl;
    
    return 0;
}