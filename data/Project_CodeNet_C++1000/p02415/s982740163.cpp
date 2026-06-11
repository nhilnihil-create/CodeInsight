#include <iostream>
#include <cctype>
#include <stdio.h>
using namespace std;
int main(void){

    char ch;

    while(1){
        scanf("%c", &ch);
        
        if(islower(ch)){
            cout <<  static_cast<char>(toupper(ch));
        }else if(isupper(ch)){
            cout << static_cast<char>(tolower(ch));
        }else{
            cout << ch;
        }
        
        if ( ch == '\n' ) break;
    }
}