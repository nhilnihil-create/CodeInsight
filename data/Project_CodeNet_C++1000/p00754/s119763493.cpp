#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <iomanip>
#include <cassert>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true){
        string s;
        getline(cin, s);
        if(s[0] == '.') break;
        int len = s.size();
        bool ok = true;
        stack<char> left_br;
        for(int i = 0; i < len; i++){
            if(s[i] == '('){
                left_br.push('(');
            }else if(s[i] == ')'){
                if(left_br.empty() || left_br.top() != '('){
                    ok = false;
                    break;
                }
                left_br.pop();
            }else if(s[i] == '['){
                left_br.push('[');
            }else if(s[i] == ']'){
                if(left_br.empty() || left_br.top() != '['){
                    ok = false;
                    break;
                }
                left_br.pop();
            }
        }
        if(ok && left_br.empty()){
            puts("yes");
        }else{
            puts("no");
        }
    }
    return 0;
}