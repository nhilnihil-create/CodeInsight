#include <iostream>
#include <math.h>
using namespace std;
string StxInt(string str, int inputI){
    string resultStr = "";
    for(int i = 0;i < inputI; i++){
        resultStr += str;
    }
    return resultStr;
}

int main(){
    string s;
    cin >> s;
    string output = "No";
    if(s.size() / 2 == floor(s.size() / 2)){
        if(s == StxInt("hi", s.size() / 2)){
            output = "Yes";
        }
    }
    cout << output << '\n';
    return 0;
}