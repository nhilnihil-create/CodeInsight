//
//  main.cpp
//  AOJ1173
//
//  Created by aki33524 on 2014/07/09.
//  Copyright (c) 2014年 aki33524. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string S;

void solve(){
    stack<char> st;
    for(int i=0; i<S.size(); i++){
        char c = S[i];
        if(c != '(' && c != ')' && c != '[' && c != ']')
            continue;
        
        if(c == '(' || c == '[')
            st.push(c);
        else if(c == ')' || c == ']'){
            if(st.empty()){
                cout << "no" << endl;
                return;
            }else if((st.top() == '(' && c == ']') || (st.top() == '[' && c == ')')){
                cout << "no" << endl;
                return;
            }
            st.pop();
        }
    }
    cout << (st.empty() ? "yes" : "no") << endl;
}

int main(int argc, const char * argv[])
{
    while(getline(cin, S), S!="."){
        solve();
    }
    return 0;
}