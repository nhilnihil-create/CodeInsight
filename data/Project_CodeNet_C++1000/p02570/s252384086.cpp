#include <iostream>

using namespace std;

int main()
{

int D,T,S;
cin >> D >> T >> S; //標準入力

int minutes;

if(D%S){
    minutes = D/S + 1;
}else{
    minutes = D/S;
}

if(minutes<=T){
    cout << "Yes\n";
}else{
    cout << "No\n";
}
}