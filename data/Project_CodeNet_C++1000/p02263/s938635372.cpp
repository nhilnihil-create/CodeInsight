#include<stack>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(void)
{
	stack<int>st;

	string str;

	int b,c,d,e,f,g;

	while(cin >> str){
		if(str[0] == '+'){
			 b = st.top();
             st.pop();
			 c = st.top();
			 st.pop();
			 st.push(b+c);
		}else if(str[0] == '-'){
			 d = st.top();
             st.pop();
			 e = st.top();
			 st.pop();
			 st.push(e-d);
		}else if(str[0] == '*'){
			 f = st.top();
             st.pop();
			 g = st.top();
			 st.pop();
			 st.push(f*g);
		}else{
		st.push(atoi(str.c_str()));
		}
	}

	cout << st.top() << endl;


	return 0;
} 