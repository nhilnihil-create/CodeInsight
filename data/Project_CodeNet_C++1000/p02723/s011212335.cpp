#include<iostream>
#include<cstring>
#include<stdbool.h>
using namespace std ;
bool coffee(char str[]){
    if(str[2]==str[3]&&str[4]==str[5]) return true;
    return false;
}

int main(){
    char str[6];
    cin >> str;
    if(coffee(str)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}