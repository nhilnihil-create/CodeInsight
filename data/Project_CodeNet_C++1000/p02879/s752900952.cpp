#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin >> a >> b;
    if(a>=1 && a<10 && b>=1 && b<10){
        cout << a * b << endl;
    }
    else{
        cout << "-1" << endl;
    }

    
}