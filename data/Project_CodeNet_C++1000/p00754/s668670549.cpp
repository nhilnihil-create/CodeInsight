//
//  main.cpp
//  The Balance of the World
//
//  Created by x15071xx on 2017/06/16.
//  Copyright ?? 2017??´ AIT. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    
    
    while(1){
        string yn = "yes";
        string str;
        vector<char> st;
        getline(cin, str);
        
        
        if (str == ".") {
            break;
        }
        
        for (int i = 0;  i < str.size(); i++) {
            
            if (str[i] == '(' || str[i] == '[') {
                st.push_back(str[i]);
            }
            
            
            if (str[i] == ')') {
                
                if (st.empty()) {
                    yn = "no";
                    break;
                }
                if ('(' != st.back()) {
                    yn = "no";
                    break;
                }
                
                st.pop_back();
                
            }
            
            if (str[i] == ']') {
                
                if (st.empty()) {
                    yn = "no";
                    break;
                }
                
                if ('[' != st.back()) {
                    yn = "no";
                    break;
                }
                
                st.pop_back();
                
            }
    
        

        }
        
        if (!st.empty()) {
            yn = "no";
        }
        
        cout << yn << endl;
    }
    return 0;
}