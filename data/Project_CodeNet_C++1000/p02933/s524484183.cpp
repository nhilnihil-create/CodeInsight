#include <iostream>
using namespace std;


int main(){
    int a;
    char s[100];
    cin >> a;
    cin >> s;

    if(a >= 3200){
        cout << s;
    }
    else{
        cout << "red";
    }

    return 0;
}