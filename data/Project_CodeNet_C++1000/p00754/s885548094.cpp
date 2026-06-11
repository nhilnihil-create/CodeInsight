#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    for(;;){
        string s;
        getline(cin, s);
        if(s == ".")
            return 0;

        int n = s.size();
        stack<char> stk;
        bool ng = false;
        for(int i=0; i<n; ++i){
            if(s[i] == '(')
                stk.push(s[i]);
            if(s[i] == '[')
                stk.push(s[i]);
            if(s[i] == ')'){
                if(stk.size() == 0 || stk.top() != '('){
                    ng = true;
                    break;
                }
                stk.pop();
            }
            if(s[i] == ']'){
                if(stk.size() == 0 || stk.top() != '['){
                    ng = true;
                    break;
                }
                stk.pop();
            }
        }

        if(!ng && stk.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}