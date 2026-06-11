#include <iostream>
using namespace std;

int main() {
    string stra,strb;
    int x;
    bool r=true;
    cin >> stra;
    cin >> strb;
    x= stra.length();
    for(int i=0;i<x;i++){
        if(stra[i]!=strb[i]){
            r=false;
        } 
    }
    if(r==true){
        cout << "Yes" << endl;
    }else if(r==false){
        cout << "No" << endl;
    }
}