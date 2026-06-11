#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    bool f=true;
    cin >> s;
    for(int i=0;i<3;i++){
        if(s[i] == s[i+1]){
            f=false;
        }
    }
    if(f){
        cout << "Good";
    }else{
        cout << "Bad";
    }
}