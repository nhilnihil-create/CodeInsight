#include<bits/stdc++.h>

using namespace std;

int main(){

    char s[3];
    cin >> s;

    if(s[0]=='S' && s[1]=='S' && s[2]=='S'){
        cout << "0" ;
    }

    else if(s[0]=='R' && s[1]=='R' && s[2]=='R'){
        cout << "3";
    }

    else if(s[0]=='R' && s[1]=='R' && s[2]=='S' || s[0]=='S' && s[1]=='R' && s[2]=='R'){
        cout << "2" ;
    }

    else  cout << "1" ;

     return 0;
}