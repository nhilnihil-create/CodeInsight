#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,j,n) for(int i = j; i < (n); i++)
#define rep0(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    string s;
    cin >> s;
    if(s[0]=='R'){
        if(s[1]=='R'){
            if(s[2]=='R'){
                cout << "3" << endl;
            }else{
                cout << "2" << endl;
            }
        }
        else{
            if(s[2]=='R'){
                cout << "1" << endl;
            }else{
                cout << "1" << endl;
            }
        }
    }
    else{
        if(s[1]=='R'){
            if(s[2]=='R'){
                cout << "2" << endl;
            }else{
                cout << "1" << endl;
            }
        }
        else{
            if(s[2]=='R'){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }
    }
}