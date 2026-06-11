#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;
int main(){
	stack<int> s;
	int n;
	string word;
	int kake,hiku,tasu,kekka;
	kekka=0;
	tasu=0;
	hiku=0;
	while(cin >> word){
		if(word=="+"){
			tasu=s.top();
			s.pop();
			tasu=tasu+s.top();
			s.pop();
			s.push(tasu);
			
		}else if(word=="-"){
			hiku=s.top();
			s.pop();
			hiku=s.top()-hiku;
			s.pop();
			s.push(hiku);
			
		}else if(word=="*"){
			kake=s.top();
			s.pop();
			kake=kake*s.top();
			s.pop();
			s.push(kake);
			
		}else{
			n=stoi(word);
			s.push(n);
		}
	}
	
	cout << s.top() << endl;
	
	
	return 0;
}