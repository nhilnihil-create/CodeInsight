#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main(void) {
    char str[105];
    while(1){
        
        cin.getline(str, sizeof(str));

        if(str[0] == '.') break;
        stack<char> s;
        s.push('0');
        int flag = 1;
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == '(') s.push(')');
            if(str[i] == '[') s.push(']');
            if(str[i] == ')'){
                if(s.top() == ')'){
                    s.pop();
                }else{
                    flag = 0;
                    break;
                }
            }

            if(str[i] == ']'){
                if(s.top() == ']'){
                    s.pop();
                }else{
                    flag = 0;
                    break;
                }
            }
        }
        
        if(flag == 1 && s.top() == '0') cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;

}