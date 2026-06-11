#include<iostream>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;
    S.push_back(T.at(S.size()));
    
    if(S == T){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}