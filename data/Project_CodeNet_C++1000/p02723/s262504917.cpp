#include<iostream>
#include<string>
using namespace std;

int main(void){

    int flg = 0;

    string s;
    cin >> s;
    
    if(s[2] == s[3]){
        if(s[4] == s[5])
            flg = 1;
     }
    

    if(flg ==  1)
    cout << "Yes" << endl;

    else
    cout << "No" << endl;

    return 0;
}