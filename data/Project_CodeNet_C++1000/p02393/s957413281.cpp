#include<iostream>
using namespace std;

int main(){
    
    int x;
    int a,b,c;
    
    cin >> a >> b >>c;  
    if(b < a){
        x = a;
        a = b;
        b = x;
    }
    if(c < a){
        x = a;
        a = c;
        c = x;
        x = b;
        b = c;
        c = x;
        cout << a << " " << b << " " << c << endl;
        return 0;
    }
    if(b > c){
        x = c;
        c = b;
        b = x;
    }
    
    cout << a << " " << b << " " << c << endl;
    
    return 0;
}