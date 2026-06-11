#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define SIZE 100

class stack{
	private:
		int top;
		int S[SIZE];
	public:
		void init(){
			top=0;
		}
	
		int pop(){
			top--;
			return S[top+1];
		}
		
		void push(int value){
			top++;
			S[top]=value;
		}
		
		void result(){
			cout<<S[top]<<endl;
		}
};

int main() {
	string word;
	stack A;
	A.init();
	while(cin>>word){
		if(word=="+"){
			int n=A.pop();
			int m=A.pop();
			A.push(n+m);
		}
		else if(word=="-"){
			int n=A.pop();
			int m=A.pop();
			A.push(m-n);
		}
		else if(word=="*"){
			int n=A.pop();
			int m=A.pop();
			A.push(n*m);
		}
		else A.push(atoi(word.c_str()));
	}
	A.result();
	return 0;
}