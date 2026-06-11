#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

int main(){
    string line;
    
    map<char, char> bracket;
    bracket[')'] = '(';
    bracket[']'] = '[';
    
    while(getline(cin, line)){
        if(line == ".") break;
        
        bool ans = true;
        stack<char> s;
        for(int i = 0;i < line.size();i++){
            char c = line[i];
            if(c == '(' || c == '[') s.push(c);
            if(c == ')' || c == ']'){
                if(s.empty() || s.top() != bracket[c]){
                    ans = false;
                    break;
                }
                s.pop();
            }
        }
        if(ans && s.empty()) cout << "yes";
        else cout << "no";
        cout << endl;
    }
    return 0;
}