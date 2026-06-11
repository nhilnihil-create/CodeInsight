#include <iostream>

using namespace std;

int main(void){
    char str[3];
    cin >> str;
    int num = 0;
    if(str[0] == 'R'){
        num++;
        if(str[0] == 'R' && str[1] == 'R'){
            num ++;
            if(str[1] == 'R' && str[2] == 'R'){       
                num ++;
            }
        }
    }
    else if(str[1] == 'R'){
        num++;
        if(str[1] == 'R' && str[2] == 'R'){
            num++;
        }
    }
    else if(str[2] == 'R'){
        num ++;
    }
    cout << num << endl;
}