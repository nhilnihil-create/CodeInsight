#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
    string T,N;
    int a;
    int b;
    while(1){
        cin >> T;
        if(T == "-") break;
        cin >> a;
        for(int i=0; i<a; i++){
            cin >> b;
            N = T.substr(0, b);
            T.insert(T.size(), N);
            T.erase(0, b);
        }
        cout << T << endl;
    }
}