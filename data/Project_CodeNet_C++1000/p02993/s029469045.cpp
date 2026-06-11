#include <bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    cin >> inp;
    int j = inp[0];
    for(int i = 1; i < inp.size(); ++i){
        if (inp[i]== j){
            cout<< "Bad"; 
            j = 10000;           
            break;
        }
        else{
            j = inp[i];
        }
    }
    if(j != 10000){
        cout<<"Good";
    }
    return 0 ;
}