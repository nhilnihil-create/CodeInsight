#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <iostream>

using namespace std;
int main(){

        char ch;
        int alp[26] ={};
        while(cin >> ch){
                if(toupper(ch) >=65 && toupper(ch) <= 90)
                        alp[toupper(ch) - 65]++;
        }

        for(int i = 0; i < 26; i++){
                printf("%c : %d\n",(i+97),alp[i]);
        }

        return 0;
}