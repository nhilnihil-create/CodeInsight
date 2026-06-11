#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string s;
vector<bool> out;

int main(){
	do{
		s.clear();
		do{
			string temp;
			getline(cin,temp);
			s+=temp;
		}while(s[s.length()-1]!='.');
		if (s.length()!=1){
			stack<bool> st;	//(=0,[=1;
			int i=0,l=s.length();
			for (;i<l;i++){
				if (s[i]=='('){
					st.push(0);
				}
				else if (s[i]=='['){
					st.push(1);
				}
				else if (s[i]==')'){
					if (st.empty()){
						out.push_back(false);
						break;
					}
					int type=st.top();
					st.pop();
					if (type!=0){
						out.push_back(false);
						break;
					}
				}
				else if (s[i]==']'){
					if (st.empty()){
						out.push_back(false);
						break;
					}
					int type=st.top();
					st.pop();
					if (type!=1){
						out.push_back(false);
						break;
					}
				}
			}
			if (i==l){
				if (st.empty()){
					out.push_back(true);
				}
				else{
					out.push_back(false);
				}
			}
		}
	}while(s.length()!=1);
	for (int i=0;i<out.size();i++){
		printf("%s\n",out[i] ? "yes" : "no");
	}
	return 0;
}