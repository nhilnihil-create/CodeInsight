#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void){
	std::priority_queue<int> q;
	int a;
	string s;
	while(cin>>s,s[2]!='d'){
		if(s[2]=='s'){
			cin>>a;
			q.push(a);
		}else{
			cout<<q.top()<<endl;
			q.pop();
		}
	}
	return 0;
}