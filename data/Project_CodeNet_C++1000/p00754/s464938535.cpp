#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


char str[104];

int main(){
    while(1){
        stack<int> st;
        bool judge = true;

        fgets(str, 104, stdin); 
        if(str[0]=='.')break;
    
        int i=0;
        while(str[i] != '.'){
            if(str[i]=='(' || str[i]=='['){
                st.push(str[i]);
            }else if(!st.empty()){
                if(str[i]==')'){
                    if(st.top() == '('){
                        st.pop();
                    }else{
                        judge = false;
                    }
                }else if(str[i]==']'){
                    if(st.top() == '['){
                        st.pop();
                    }else{
                        judge = false;
                    }
                }
            }else if(st.empty()){
                if(str[i]==')' || str[i]==']') judge = false;
            }
            if(judge==false){
                break;
            }
            i++;
        }
        if(!st.empty()){
            judge = false;
        }
        if(judge){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }

}
