#include <bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    cin >> inp;
    if(inp=="SUN"){
        cout << 7;
    }
    else if(inp=="MON"){
        cout << 6;
    }
    else if(inp=="TUE"){
        cout << 5;
    }
    else if(inp=="WED"){
        cout << 4;
    }
    else if(inp=="THU"){
        cout << 3;
    }
    else if(inp=="FRI"){
        cout << 2;
    } 
    else{
        cout<< 1;
    }  
    return 0;
}