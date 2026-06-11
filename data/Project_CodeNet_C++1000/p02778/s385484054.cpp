#include<iostream>
#include<string>
using namespace std;

int main(){
    string S, result;
    cin >> S;

    result = "";
    for (int i=0; i<S.size(); i++){
        result += "x";
    }

    cout << result << endl;
}