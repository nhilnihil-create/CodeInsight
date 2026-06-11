#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n,count=0;
	cin >> n;
	int i;
	queue<string> q;
	for(i = 1;i < 10;i++)
		q.push(to_string(i));
		
	while(1){
		int m = q.size(),i;
		
		for(i = 0;i < m;i++){
			string s = q.front();
			q.pop();
			if(++count == n){
				cout << s;
				return 0;
			}
			
			if(s.back() == '0'){
				q.push(s+'0'),q.push(s+'1');
			}		
			else if(s.back() == '9'){
				q.push(s+'8'),q.push(s+'9');
			}
				
			else{
				q.push(s+(char)(s.back()-1));
				q.push(s+(char)(s.back()));
				q.push(s+(char)(s.back()+1));
			}
				
		}
	}
} 