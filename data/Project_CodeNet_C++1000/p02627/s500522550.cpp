#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    char al;
    cin >> al;
    if(islower(al)) cout << 'a' << endl;
    else  cout << 'A' << endl;
    
    return 0;
}