#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    int x;

    for(int i = 1; i < 6; i++){
        cin >> x;
        if(x == 0) cout << i << endl;
    }
    
    return 0;
}