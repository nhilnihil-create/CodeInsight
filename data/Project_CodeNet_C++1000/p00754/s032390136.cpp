/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp*/
 
#include <iostream>
#include <stack>
 
using namespace std;

int main()
{
    string s;
 
    while(getline(cin,s) && s!="."){
    	bool is_yes=true;
    	stack<char> stack;
    	
    	for(int i=0;is_yes && i<s.length();i++){
    		if(s[i]=='(' || s[i]=='['){
    			stack.push(s[i]);
    		}else if(s[i]==')' || s[i]==']'){
    			if((s[i]==')' && 0<stack.size() && stack.top()=='(') || (s[i]==']' && 0<stack.size() && stack.top()=='[')){
    				stack.pop();
    			}else{
    				is_yes=false;
    			}
    		}
    	}
    	if(is_yes && stack.size()==0){
    		cout<<"yes"<<endl;
    	}else{
    		cout<<"no"<<endl;
    	}
     }
    return 0;
}