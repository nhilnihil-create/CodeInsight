#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin, str), str != "."){
        stack<char> kakko;
        int i;
        for(i=0; i<str.size(); ++i){
            if(str[i] == '(' || str[i] == '[') kakko.push(str[i]);
            if(str[i] == ')' || str[i] == ']'){
                if(kakko.size() == 0) break;
                else{
                    if((kakko.top()=='(')?str[i]==')':str[i]==']') kakko.pop();
                    else break;
                }
            }
        }
        cout << ((i==str.size()&&kakko.size()==0)?"yes":"no") << endl;
    }
    return 0;
}