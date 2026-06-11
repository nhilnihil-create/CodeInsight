// CPP program to demonstrate use of std::map 
#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>
#include<string.h>
using namespace std;
int main(){ 
    int N,X,T;
    cin >> N;
    cin >> X;
    cin >> T;
    int times;
    if(N%X == 0 ){
        times=(N/X);
    }
    else{
        times=(N/X)+1;
    }
    cout << times*T << endl;
    return 0;
}