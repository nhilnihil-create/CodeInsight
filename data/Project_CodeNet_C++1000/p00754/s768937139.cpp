#include <iostream>
#include <stack>
using namespace std;

char bl[5]= "([)]";

int main(){
    string str;
    while(getline(cin,str) && str[0]!='.'){
        stack<char> stk;
        for(int i=0; str[i]!='.'; i++){
            for(int j=0; j<2; j++){
                if(str[i]==bl[j]){
                    stk.push(str[i]);
                }
            }
            for(int j=2; j<4; j++){
                if(str[i]==bl[j]){
                    if(stk.empty() || stk.top()!=bl[j-2]){
                        stk.push(0);
                        break;
                    }else{
                        stk.pop();
                    }
                }
            }
        }
        
        if(stk.empty()){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

    return 0;
}