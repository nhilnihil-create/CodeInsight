#include<iostream>

using namespace std;

int main() {
    int a,b;
    char c;
    while(1){
        cin >> a >> c >> b;
        if(c == '?') break;
        switch(c){
            case '+' :
                cout << a+b;
                break;
            case '-' :
                cout << a-b;
                break;
            case '*' :
                cout << a*b;
                break;
            case '/' :
                cout << a/b;
                break;
        }
    cout << endl;
    }
}