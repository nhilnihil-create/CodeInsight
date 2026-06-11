#include <iostream>
#include <stack>
using namespace std;

int main(){

    string s;


    while (1){
	bool b = true;
	
	getline(cin, s);
	if (s == ".") break;

	stack<char> st;
	
	for (int i = 0; i < s.size(); i++){
	    
	    switch (s[i]){
	    case '(': st.push('('); break;
	    case ')':
		if (st.empty() || st.top() != '(') b = false;
		else st.pop();
		break;
	    case '[': st.push('['); break;
	    case ']':
		if (st.empty() || st.top () != '[') b = false;
		else st.pop();
		break;
	    default: break;
	    }
	}

	if (b && st.empty()) cout << "yes" << endl;
	else cout << "no" << endl;
    }

}