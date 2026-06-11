#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    bool ans;
    getline(cin, str);
    while(str != "."){
        stack<int> bra;
        ans = true;
        for(string::iterator it=str.begin();it!=str.end();++it){
            switch(*it){
                case '(':
                    bra.push(1);
                    break;
                case '[':
                    bra.push(0);
                    break;
                case ')':
                    if(bra.empty()) ans = false;
                    else{
                        if(bra.top()!=1) ans = false;
                        bra.pop();
                    }
                    break;
                case ']':
                    if(bra.empty()) ans = false;
                    else{
                        if(bra.top()!=0) ans = false;
                        bra.pop();
                    }
                    break;
            }
            if(!ans) break;
        }
        if(!bra.empty()) ans = false;
        cout << (ans?"yes":"no") << endl;
        getline(cin, str);
    }
}