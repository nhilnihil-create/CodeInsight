#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void){
    string input;
    
    while(getline(cin, input), !cin.eof()){
        int a, b, c;
        int cnt = 0;
        sscanf(input.c_str(), "%d %d %d\n", &a, &b, &c);
        
        for(int i = a; i < b + 1; i++){
            if(c % i == 0){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return(0);
}

