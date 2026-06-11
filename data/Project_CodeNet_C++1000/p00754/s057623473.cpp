#include <iostream>
#include <string>

using namespace std;

int main(){
    while(true){
        // 1?????\???
        string s;
        getline(cin, s);

        // .??????????????????
        if(s == ".")
            return 0;

        // rb(round), sb(square)
        string stack = "";

        //??¨??????????????????
        for(auto &x:s){
            // ?????¬??§
            if(x == '(' || x == '[')
                // stack?????????
                stack.push_back(x);
            // ?????¬??§
            else if(x == ')' || x == ']'){
                // stack?????? ??? no
                if(stack.empty()){
                    stack.push_back('.');
                    break;
                // ??¬??§?????????????????????
                }else if(x == ')' && stack.back() == '('){
                    stack.pop_back();
                }else if(x == ']' && stack.back() == '['){
                    stack.pop_back();
                // no
                }else {
                    stack.push_back('.');
                    break;
                }
            }
        }

        // ??????0??????yes
        if(stack.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}