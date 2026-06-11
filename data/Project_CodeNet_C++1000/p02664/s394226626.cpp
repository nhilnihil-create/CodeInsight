#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){

        if(s[i] == '?'){
            if(s[i-1] == 'P'){
                s[i] = 'D';
            }
            else if(s[i+1] == 'D'){
                s[i] = 'P';
            }
            else if(s[i+1] == '?'){
                s[i] = 'P';
                s[i+1] = 'D';
            }
            else
            {
                s[i] = 'D';
            }
            
        }

    }

    cout << s;

    return 0;
}