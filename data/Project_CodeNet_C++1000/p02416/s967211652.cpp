#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
 
using namespace std;
 
int main(void){
    while (true){
        int ans = 0;
        string number;
        getline(cin, number);
        if (number == "0") break;
        for (int i = 0; i < number.size(); i++) {
            ans = ans + (number[i] - '0');
        }
        cout << ans << endl;
    }
}