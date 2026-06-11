#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
	for(;;){
		string word;
		stack<int> log;
		getline(cin,word);
		if(word == "."){break;}
		for(int i=0; i<word.size(); i++){
			if(word[i] == '('){log.push(1);}
			if(word[i] == '['){log.push(2);}
			if(word[i] == ')'){
				if(log.empty()){cout<<"no"<<endl;goto jump;}
				else if(log.top() == 1){log.pop();}
				else if(log.top() != 1){cout<<"no"<<endl;goto jump;}
			}
			if(word[i] == ']'){
				if(log.empty()){cout<<"no"<<endl;goto jump;}
				else if(log.top() == 2){log.pop();}
				else if(log.top() != 2){cout<<"no"<<endl;goto jump;}
			}
		}
		if(log.empty()){cout <<"yes"<<endl;}
		else{cout <<"no"<<endl;}
		jump:;
	}
}