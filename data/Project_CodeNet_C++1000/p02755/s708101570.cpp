#include<bits/stdc++.h>
using namespace std;

// floor(X*0.08) = A and floor(X*0.1) = B なる整数Xを求めよ。 
// Xの最大値は1000 (1000*0.1= 100より)

int main(){
    int A, B; //1 ~ 100の整数
    cin >> A >> B; 
    int X = 1;
    while (X <= 1000){
        int a = (int) (X*0.08);
        int b = (int) (X*0.1);
        if( a == A && b == B){
            cout << X << endl;
            return 0;
        } 
        X++;
    }
    cout << "-1" << endl;
}