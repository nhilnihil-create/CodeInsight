#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	string S;
	int n=0;
	stack<int> T[92000];
	bool hantei=true;

	while (true){
		getline(cin,S);
		hantei=true;
		if(S=="."){
			break;
		}
		for(int i=0;i<S.size();i++){
			if(S[i]=='(' || S[i]=='['){
				T[n].push(S[i]);
			}
			if(S[i]==')' || S[i]==']'){
				if(T[n].empty()){
					hantei=false;
				}
				else{
					if((T[n].top()=='(' && S[i]==']')|| (T[n].top()=='[' && S[i]==')')){
						hantei=false;
					}
					T[n].pop();
				}
			}
		}
		if(T[n].empty()==false){
			hantei=false;
		}
		cout<<(hantei?"yes":"no")<<endl;
		n++;
	}
	return 0;
}