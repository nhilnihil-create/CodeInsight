#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;
 
int x, y, s;
int main() {
    while(1){
        string str; getline(cin, str);
        
        if(str == ".") break;
        stack<char> stk;
        int n=str.size();
        bool ok = true;
        for(int i=0; i<n; ++i){
            if(str[i]=='('||str[i]=='[') stk.push(str[i]);
            
            if(str[i]==')'){
                if(stk.empty()) ok = false;
                else if(stk.top()=='('){
                    stk.pop();
                }else{
                    ok = false;
                }
            }
            if(str[i]==']'){
                if(stk.empty()) ok = false;
                else if(stk.top()=='['){
                    stk.pop();
                }else{
                    ok = false;
                }
            }
            if(str[i]=='.'||str[i]==' ') continue;
            if(!ok) break;
        }
        if(!ok||!stk.empty()) cout << "no" << endl;
        else cout <<"yes" << endl;
    }
    return 0;
}
