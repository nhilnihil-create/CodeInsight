#include <iostream>
using namespace std;

int main(){
    string x,y;
    while(cin >> x >> y){
        int aa,bb;
        cin >> aa >> bb;
        string str;
        cin >> str;
        if(str==x){
            aa-=1;
            cout << aa << " " << bb << '\n';
        }else{
            bb-=1;
            cout << aa << " " << bb << '\n';
        }
    }
}